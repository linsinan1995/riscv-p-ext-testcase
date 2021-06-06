/* smax8 also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for smax8 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64i_zpn_zprv_zpsf -mabi=lp64 -O0" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t xams (uint32_t ra, uint32_t rb)
{
  return __rv__smax8 (ra, rb);
}

static __attribute__ ((noinline))
int8x8_t xams_v (int8x8_t ra, int8x8_t rb)
{
  return __rv__v_smax8 (ra, rb);
}
/* { dg-final { scan-assembler-times "smax8" 3 } } */
/* { dg-final { scan-assembler-times "builtin_riscv" 0 } } */
