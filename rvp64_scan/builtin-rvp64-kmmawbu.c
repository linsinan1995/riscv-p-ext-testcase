/* This is a test program for kmmawb.u instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64i_zpn_zprv_zpsf -mabi=lp64 -O0" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int32_t ubwammk (int32_t rd, int32_t ra, int32_t rb)
{
  return __rv__kmmawb_u (rd, ra, rb);
}

static __attribute__ ((noinline))
int32x2_t ubwammk_v (int32x2_t rd, int32x2_t ra, int16x4_t rb)
{
  return __rv__v_kmmawb_u (rd, ra, rb);
}
/* { dg-final { scan-assembler-times "kmmawb.u" 2 } } */
/* { dg-final { scan-assembler-times "builtin_riscv" 0 } } */
