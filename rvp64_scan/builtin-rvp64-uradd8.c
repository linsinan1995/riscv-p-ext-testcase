/* This is a test program for uradd8 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zpsf_zprv -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t ddaru (uint32_t ra, uint32_t rb)
{
  return __rv__uradd8 (ra, rb);
}

static __attribute__ ((noinline))
uint8x8_t ddaru_v (uint8x8_t ra, uint8x8_t rb)
{
  return __rv__v_uradd8 (ra, rb);
}
/* { dg-final { scan-assembler-times "uradd8" 3 } } */
