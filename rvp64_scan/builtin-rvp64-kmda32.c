/* This is a test program for kmda32 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zpsf_zprv -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int32_t admk (uint32_t ra, uint32_t rb)
{
  return __rv__kmda32 (ra, rb);
}

static __attribute__ ((noinline))
int32_t admk_v (int32x2_t ra, int32x2_t rb)
{
  return __rv__v_kmda32 (ra, rb);
}
/* { dg-final { scan-assembler-times "kmda32" 3 } } */
