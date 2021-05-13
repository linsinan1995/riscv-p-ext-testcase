/* This is a test program for kmaxda32 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zpsf_zprv -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int32_t adxamk (uint32_t rd, uint32_t ra, uint32_t rb)
{
  return __rv__kmaxda32 (rd, ra, rb);
}

static __attribute__ ((noinline))
int32_t adxamk_v (int32_t rd, int32x2_t ra, int32x2_t rb)
{
  return __rv__v_kmaxda32 (rd, ra, rb);
}
/* { dg-final { scan-assembler-times "kmaxda32" 3 } } */
