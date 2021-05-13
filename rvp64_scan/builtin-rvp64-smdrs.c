/* This is a test program for smdrs instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zpsf_zprv -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int32_t srdms (uint32_t ra, uint32_t rb)
{
  return __rv__smdrs (ra, rb);
}

static __attribute__ ((noinline))
int32x2_t srdms_v (int16x4_t ra, int16x4_t rb)
{
  return __rv__v_smdrs (ra, rb);
}
/* { dg-final { scan-assembler-times "smdrs" 3 } } */
