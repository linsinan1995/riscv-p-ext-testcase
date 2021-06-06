/* This is a test program for kmmawt2.u instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64i_zpn_zprv_zpsf -mabi=lp64 -O0" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int32_t u2twammk (int32_t rd, int32_t ra, int32_t rb)
{
  return __rv__kmmawt2_u (rd, ra, rb);
}

static __attribute__ ((noinline))
int32x2_t u2twammk_v (int32x2_t rd, int32x2_t ra, int16x4_t rb)
{
  return __rv__v_kmmawt2_u (rd, ra, rb);
}
/* { dg-final { scan-assembler-times "kmmawt2.u" 2 } } */
/* { dg-final { scan-assembler-times "builtin_riscv" 0 } } */
