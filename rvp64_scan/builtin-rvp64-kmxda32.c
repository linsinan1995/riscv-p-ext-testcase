/* This is a test program for kmxda32 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zpsf_zprv -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int32_t adxmk (uint32_t ra, uint32_t rb)
{
  return __rv__kmxda32 (ra, rb);
}

static __attribute__ ((noinline))
int32_t adxmk_v (int32x2_t ra, int32x2_t rb)
{
  return __rv__v_kmxda32 (ra, rb);
}
/* { dg-final { scan-assembler-times "kmxda32" 3 } } */
