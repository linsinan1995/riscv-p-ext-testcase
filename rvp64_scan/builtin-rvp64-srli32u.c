/* This is a test program for srli32u instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zpsf_zprv -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t u23ilrs (uint32_t ra)
{
  return __rv__srl32_u (ra, 4);
}

static __attribute__ ((noinline))
uint32x2_t u23ilrs_v (uint32x2_t ra)
{
  return __rv__v_srl32_u (ra, 4);
}
/* { dg-final { scan-assembler-times "srl32_u" 2 } } */
