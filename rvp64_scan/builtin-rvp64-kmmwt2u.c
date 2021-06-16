/* This is a test program for kmmwt2u instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64i_zpn_zpsf -mabi=lp64 -O0" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int64_t u2twmmk (int64_t ra, uint64_t rb)
{
  return __rv_kmmwt2_u (ra, rb);
}

static __attribute__ ((noinline))
int32x2_t u2twmmk_v (int32x2_t ra, int16x4_t rb)
{
  return __rv_v_kmmwt2_u (ra, rb);
}
/* { dg-final { scan-assembler-times "kmmwt2.u" 2 } } */
/* { dg-final { scan-assembler-times "builtin_riscv" 0 } } */
