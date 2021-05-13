/* This is a test program for kmabb32 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zpsf_zprv -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int32_t bbamk (uint32_t rd, uint32_t ra, uint32_t rb)
{
  return __rv__kmabb32 (rd, ra, rb);
}

static __attribute__ ((noinline))
int32_t bbamk_v (uint32_t rd, int32x2_t ra, int32x2_t rb)
{
  return __rv__v_kmabb32 (rd, ra, rb);
}
/* { dg-final { scan-assembler-times "kmabb32" 3 } } */
