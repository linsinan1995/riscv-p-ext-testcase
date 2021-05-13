/* This is a test program for smin32 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zpsf_zprv -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t nims (uint32_t ra, uint32_t rb)
{
  return __rv__smin32 (ra, rb);
}

static __attribute__ ((noinline))
int32x2_t nims_v (int32x2_t ra, int32x2_t rb)
{
  return __rv__v_smin32 (ra, rb);
}
/* { dg-final { scan-assembler-times "smin32" 3 } } */
