/* smin8 also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for smin8 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64i_zpn_zpsf -mabi=lp64 -O0" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint64_t nims (uint64_t ra, uint64_t rb)
{
  return __rv_smin8 (ra, rb);
}

static __attribute__ ((noinline))
int8x8_t nims_v (int8x8_t ra, int8x8_t rb)
{
  return __rv_v_smin8 (ra, rb);
}
/* { dg-final { scan-assembler-times "smin8" 3 } } */
/* { dg-final { scan-assembler-times "builtin_riscv" 0 } } */
