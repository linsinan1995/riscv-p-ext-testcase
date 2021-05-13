'''
 # @ Author: Sinan Lin
 # @ Email: sinan.lin@nokia.com
 # @ Create Time: 2021-05-08 15:07:45
 # @ Modified by: Sinan Lin
 # @ Modified time: 2021-05-13 16:48:01
 # @ Description:
 '''
from collections import defaultdict
from dataclasses import dataclass
import os

@dataclass
class Inst:
    counter:int = 0
    inst_in_filename:bool = False

def regex_and_write(original_path, new_path, xlen):
    assert (xlen == 32 or xlen == 64)

    for src_path, out_path in zip(original_path, new_path):
        opt_level = None
        subset = None
        found_main = False
        out_content = None
        func_name = None
        name_to_inst = defaultdict(Inst)
        name_change = []
        infos = []
        
        # do not forget there is an attribute like .file   "testadd.c"
        out_file_name = out_path.split('/')[1]
        
        with open(src_path, "r") as f:
            content = f.readlines()
            out_content = content

            assert(out_content and len(out_content) > 0)

            for idx, line in enumerate(out_content):
                # subset
                if "#if defined(__riscv_z" in line:
                    subset = line.split("#if defined(__riscv_")[1].split(")")[0]
                    out_content.pop(idx)
                    continue
                # dg command
                if "dg" in line:
                    # remove line
                    if "dg-do" in line:
                        # print(line.strip())
                        if "dg-do run" in line:
                            out_content.pop(idx) #delete
                        else:
                            raise PermissionError("unreachable area!")

                    # save optimization level
                    elif "dg-options" in line:
                        opt_level = line.strip().split("-O")[1].split("\"")[0]
                        out_content.pop(idx) #delete
                    else:
                        raise PermissionError("unreachable area!")
                
                if len(content) > idx + 1:
                    # find int main
                    if "int" in line and "main" in content[idx+1]:
                        found_main = True
                        end_line = idx
                        if len(content[idx-1].strip()) == 0:
                            end_line -= 1

                        out_content = out_content[:(end_line)]
                        break
                
                # return __rv__
                # for scan
                if "return __rv__" in line:
                    inst_name = line.strip().split("return __rv__")[1].split(" ")[0]
                    if "v_" in inst_name:
                        inst_name = inst_name[2:]

                    # uadd8 -> add8
                    elif inst_name[0] in ('s', 'u'):
                        if inst_name[1:4] == "add" or inst_name[1:4] == "sub":
                            inst_name = inst_name[1:]
                        elif inst_name[1:6] == "cmpeq":
                            inst_name = inst_name[1:]
                        elif inst_name[1:5] in ("cras", "crsa"):
                            inst_name = inst_name[1:]
                    elif inst_name[-2:] == "_u":
                        inst_name = inst_name[:-2] + ".u"

                    name_to_inst[inst_name].counter += 1
                    
                    continue

                if idx > 0 and "__attribute__" in content[idx-1]:
                    func_decl = line.split(" ")
                    func_name = func_decl[1]
                    new_func_name = func_name[::-1]

                    while new_func_name[0].isdigit():
                        new_func_name = new_func_name[1:]

                    func_decl[1] = new_func_name
                    name_change.append(" ".join(func_decl))

        if not found_main:
            print(f"Wrong foramt {src_path}")
        
        assert(len(name_to_inst.items()))
        for key, val in name_to_inst.items():
            if key == "add64" and xlen == 64:
                infos.append("/* add64 will generate 'add' in rv64p */\n")
                name_to_inst[key].counter = 0

            # instruction is included in file name
            val.inst_in_filename |= key in out_file_name
            total_time = val.counter + val.inst_in_filename
            out_content.insert(len(out_content), "/* { dg-final { scan-assembler-times \"" + key + '" ' + str(total_time) + " } } */\n")
            if val.inst_in_filename:
                infos.append(f"/* {key} also appears on filename, so scan-assembler-times plus 1 */\n")

        # change function name
        for idx, line in enumerate(out_content):
            if idx > 0 and "__attribute__" in out_content[idx-1]:
                out_content[idx] = name_change.pop(0)

        assert(len(name_change)==0)

        if xlen == 32:
            # zprv is rv64 only
            assert(subset != "zprv")
            if subset == "zpn":
                pass
            elif subset == "zpsf":
                subset = "zpn_zpsf"
            else:
                raise PermissionError("unreachable area!")
        else:
            subset = "zpn_zprv_zpsf"
        
        abi = "lp64" if xlen == 64 else "ilp32"
        opt_level = opt_level if opt_level else '2'
        out_content.insert(1, "/* { dg-do compile { target riscv"+ str(xlen) +"*-*-* } } */\n")
        out_content.insert(2, "/* { dg-options } " + "\""+ f"-march=rv{xlen}i_{subset} -mabi={abi} -O{opt_level}" + '" */\n')

        for info in infos:
            out_content.insert(0, info)

        with open(out_path, "w") as f:
            f.writelines(out_content)

# /* { dg-do compile } */
# /* { dg-options "-march=rv64gc_zkne -mabi=lp64 -O2" } */
# /* { dg-final { scan-assembler-times "aes64ds" 2 } } */

if __name__ == "__main__":
    all_path = []
    out_path = []
    root_files = "rvp32_scan"

    # save all file in rvp dir
    for root, dirs, files in os.walk("rvp", topdown=False):
        for name in files:
            all_path.append(os.path.join(root, name))
            out_path.append(os.path.join(root_files, name))
        print(f"Total test case in dir rvp: {len(all_path)}")
    
    regex_and_write(original_path=all_path, new_path=out_path, xlen=32)

    all_path = []
    out_path = []
    root_files = "rvp64_scan"

    # save all file in rvp dir
    for root, dirs, files in os.walk("rvp64", topdown=False):
        for name in files:
            all_path.append(os.path.join(root, name))
            out_path.append(os.path.join(root_files, name))
        print(f"Total test case in dir rvp64: {len(all_path)}")
    
    regex_and_write(original_path=all_path, new_path=out_path, xlen=64)
