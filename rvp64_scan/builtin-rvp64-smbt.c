/* This is a test program for smbt instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zprv_zpsf -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int32_t tbms (uint32_t ra, uint32_t rb)
{
  return __rv__smbt16 (ra, rb);
}

static __attribute__ ((noinline))
int32x2_t tbms_v (int16x4_t ra, int16x4_t rb)
{
  return __rv__v_smbt16 (ra, rb);
}
/* { dg-final { scan-assembler-times "smbt16" 2 } } */