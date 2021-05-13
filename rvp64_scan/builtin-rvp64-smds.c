/* This is a test program for smds instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zpsf_zprv -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int32_t sdms (uint32_t ra, uint32_t rb)
{
  return __rv__smds (ra, rb);
}

static __attribute__ ((noinline))
int32x2_t sdms_v (int16x4_t ra, int16x4_t rb)
{
  return __rv__v_smds (ra, rb);
}
/* { dg-final { scan-assembler-times "smds" 3 } } */
