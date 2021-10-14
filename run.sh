#!/bin/bash
GCC=riscv64-unknown-elf-gcc
log_path=rvp_test.log
compile=0
execute=0
test_dir=
riscv_home=
status=
fail_compile=0
fail_execute=0
pass_compile=0
pass_execute=0

Help()
{
   echo "Helper script to run rvp test."
   echo
   echo "options:"
   echo "--compile test_dir       compile only"
   echo "--execute test_dir       execution test"
   echo "--toolchain path         toolchain bin path(with spike and pk)"
   echo "e.g. ./run.sh --execute rvp64_exec --toolchain ~/riscv-gnu-toolchain/obj-rv64gcp/bin"
   echo
}

ARGUMENT_LIST=(
    "compile"
    "execute"
    "toolchain"
)

# read arguments
opts=$(getopt \
    --longoptions "$(printf "%s:," "${ARGUMENT_LIST[@]}")" \
    --name "$(basename "$0")" \
    --options "" \
    -- "$@"
)

eval set --$opts

while [[ $# -gt 0 ]]; do
    case "$1" in
        --compile)
            compile=1
            test_dir="$2"
            shift 2
            ;;
        --execute)
            execute=1
            test_dir="$2"
            shift 2
            ;;
        --toolchain)
            riscv_home=$2
            shift 2
            ;;
        *)
            Help
            break
            ;;
    esac
done

get_status() {
	local return_val=$1
    if [ "$return_val" != "0" ]; then
        status="FAIL"
    else
        status="PASS"
    fi
}

run_test() {
    CFLAGS=$1
    rm $log_path
    for filename in $test_dir/*.c; do
        $riscv_home/$GCC $CFLAGS $filename 2>> $log_path 1> /dev/null

        if [ "$?" != "0" ]; then
            status="FAIL"
            ((fail_compile++))
        else
            status="PASS"
            ((pass_compile++))
        fi
        echo "$status,compile,$filename" >> $log_path

        if [ "$CFLAGS" != "-S" ] ; then
            if [ "$status" == "PASS" ] ; then
                $riscv_home/spike --isa=RV64GCP pk a.out 2>> $log_path 1> /dev/null

                if [ "$?" != "0" ]; then
                    status="FAIL"
                    ((fail_execute++))
                else
                    status="PASS"
                    ((pass_execute++))
                fi
                echo "$status,execute,$filename" >> $log_path
            fi
        fi
    done
    echo "Done, see $log_path for more information!"
    echo "# fail to compile $fail_compile, success to compile $pass_compile"
    if [ "$CFLAGS" != "-S" ] ; then
        echo "# fail to execute $fail_execute, success to execute $pass_execute"
    fi
}

if [ $execute == 1 ] ; then
    run_test
elif [ $compile == 1 ] ; then
    run_test -S
fi