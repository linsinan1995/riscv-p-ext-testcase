/* This is a test program for kmmawb2.u instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O0" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int64_t u2bwammk (int64_t rd, int64_t ra, uint64_t rb)
{
  return __rv_kmmawb2_u (rd, ra, rb);
}

static __attribute__ ((noinline))
int32x2_t u2bwammk_v (int32x2_t rd, int32x2_t ra, int16x4_t rb)
{
  return __rv_v_kmmawb2_u (rd, ra, rb);
}
/* { dg-final { scan-assembler-times "kmmawb2.u" 2 } } */
/* { dg-final { scan-assembler-times "builtin_riscv" 0 } } */
