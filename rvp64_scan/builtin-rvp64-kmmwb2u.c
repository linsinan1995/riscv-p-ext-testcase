/* This is a test program for kmmwb2u instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zprv_zpsf -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int32_t u2bwmmk (int32_t ra, int32_t rb)
{
  return __rv__kmmwb2_u (ra, rb);
}

static __attribute__ ((noinline))
int32x2_t u2bwmmk_v (int32x2_t ra, int16x4_t rb)
{
  return __rv__v_kmmwb2_u (ra, rb);
}
/* { dg-final { scan-assembler-times "kmmwb2.u" 1 } } */
/* { dg-final { scan-assembler-times "kmmwb2_u" 1 } } */
