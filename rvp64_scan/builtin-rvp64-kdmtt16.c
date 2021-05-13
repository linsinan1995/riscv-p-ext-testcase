/* This is a test program for kdmtt16 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zpsf_zprv -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int32_t ttmdk (uint32_t ra, uint32_t rb)
{
  return __rv__kdmtt16 (ra, rb);
}

static __attribute__ ((noinline))
int32x2_t ttmdk_v (int16x4_t ra, int16x4_t rb)
{
  return __rv__v_kdmtt16 (ra, rb);
}
/* { dg-final { scan-assembler-times "kdmtt16" 3 } } */
