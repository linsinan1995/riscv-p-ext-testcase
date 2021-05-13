/* This is a test program for smxds instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zpsf_zprv -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int32_t sdxms (uint32_t ra, uint32_t rb)
{
  return __rv__smxds (ra, rb);
}

static __attribute__ ((noinline))
int32x2_t sdxms_v (int16x4_t ra, int16x4_t rb)
{
  return __rv__v_smxds (ra, rb);
}
/* { dg-final { scan-assembler-times "smxds" 3 } } */
