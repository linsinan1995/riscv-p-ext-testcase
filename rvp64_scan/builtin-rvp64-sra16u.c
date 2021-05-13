/* This is a test program for sra16.u instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zpsf_zprv -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t u61ars (uint32_t ra, uint32_t rb)
{
  return __rv__sra16_u (ra, rb);
}

static __attribute__ ((noinline))
int16x4_t u61ars_v (int16x4_t ra, uint32_t rb)
{
  return __rv__v_sra16_u (ra, rb);
}
/* { dg-final { scan-assembler-times "sra16_u" 2 } } */
