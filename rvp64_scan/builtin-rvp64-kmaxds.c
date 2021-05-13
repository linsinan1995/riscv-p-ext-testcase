/* This is a test program for kmaxds instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zpsf_zprv -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int32_t sdxamk (uint32_t rd, uint32_t ra, uint32_t rb)
{
  return __rv__kmaxds (rd, ra, rb);
}

static __attribute__ ((noinline))
int32x2_t sdxamk_v (int32x2_t rd, int16x4_t ra, int16x4_t rb)
{
  return __rv__v_kmaxds (rd, ra, rb);
}
/* { dg-final { scan-assembler-times "kmaxds" 3 } } */
