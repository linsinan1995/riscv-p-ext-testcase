/* sub64 also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for sub64 instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32i_zpn_zpsf -mabi=ilp32 -O0" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int64_t buss (int64_t ra, int64_t rb)
{
  return __rv__ssub64 (ra, rb);
}

static __attribute__ ((noinline))
uint64_t busu (uint64_t ra, uint64_t rb)
{
  return __rv__usub64 (ra, rb);
}
/* { dg-final { scan-assembler-times "sub64" 3 } } */
/* { dg-final { scan-assembler-times "builtin_riscv" 0 } } */
