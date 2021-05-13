/* This is a test program for ksll16 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zpsf_zprv -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t llsk (uint32_t ra, uint32_t rb)
{
  return __rv__ksll16 (ra, rb);
}

static __attribute__ ((noinline))
int16x4_t llsk_v (int16x4_t ra, uint32_t rb)
{
  return __rv__v_ksll16 (ra, rb);
}
/* { dg-final { scan-assembler-times "ksll16" 3 } } */
