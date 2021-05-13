/* This is a test program for smar64 instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options } "-march=rv32i_zpn_zpsf -mabi=ilp32 -O2" */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int64_t rams (int64_t t, int a, int b)
{
  return __rv__smar64 (t, a, b);
}
/* { dg-final { scan-assembler-times "smar64" 2 } } */
