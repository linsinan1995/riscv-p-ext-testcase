/* This is a test program for radd64 instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options } "-march=rv32i_zpn_zpsf -mabi=ilp32 -O2" */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int64_t ddar (int64_t ra, int64_t rb)
{
  return __rv__radd64 (ra, rb);
}
/* { dg-final { scan-assembler-times "radd64" 2 } } */
