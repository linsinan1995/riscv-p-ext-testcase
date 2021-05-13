/* This is a test program for ksll32 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zpsf_zprv -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t llsk (uint32_t ra, uint32_t rb)
{
  return __rv__ksll32 (ra, rb);
}

static __attribute__ ((noinline))
int32x2_t llsk_v (int32x2_t ra, uint32_t rb)
{
  return __rv__v_ksll32 (ra, rb);
}
/* { dg-final { scan-assembler-times "ksll32" 3 } } */
