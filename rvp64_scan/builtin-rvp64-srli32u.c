/* This is a test program for srli32u instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64i_zpn_zprv_zpsf -mabi=lp64 -O0" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint64_t u23ilrs (uint64_t ra)
{
  return __rv__srl32_u (ra, 4);
}

static __attribute__ ((noinline))
uint32x2_t u23ilrs_v (uint32x2_t ra)
{
  return __rv__v_srl32_u (ra, 4);
}
/* { dg-final { scan-assembler-times "srl32.u" 2 } } */
/* { dg-final { scan-assembler-times "builtin_riscv" 0 } } */
