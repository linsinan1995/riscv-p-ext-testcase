/* This is a test program for add8 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zpsf_zprv -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int32_t pilcu (int32_t ra)
{
  return __rv__uclip32 (ra, 5);
}
/* { dg-final { scan-assembler-times "uclip32" 2 } } */
