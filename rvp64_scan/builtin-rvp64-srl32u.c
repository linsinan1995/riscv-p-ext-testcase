/* This is a test program for srl32u instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64i_zpn_zprv_zpsf -mabi=lp64 -O0" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint64_t u23lrs (uint64_t ra, uint32_t rb)
{
  return __rv__srl32_u (ra, rb);
}

static __attribute__ ((noinline))
uint32x2_t u23lrs_v (uint32x2_t ra, uint32_t rb)
{
  return __rv__v_srl32_u (ra, rb);
}
/* { dg-final { scan-assembler-times "srl32.u" 2 } } */
/* { dg-final { scan-assembler-times "builtin_riscv" 0 } } */
