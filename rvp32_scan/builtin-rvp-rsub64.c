/* This is a test program for rsub64 instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options } "-march=rv32i_zpn_zpsf -mabi=ilp32 -O2" */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int64_t busr (int64_t ra, int64_t rb)
{
  return __rv__rsub64 (ra, rb);
}
/* { dg-final { scan-assembler-times "rsub64" 2 } } */
