/* This is a test program for kslra16 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zprv_zpsf -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t u61arlsk (uint32_t ra, uint32_t rb)
{
  return __rv__kslra16_u (ra, rb);
}

static __attribute__ ((noinline))
int16x4_t u61arlsk_v (int16x4_t ra, uint32_t rb)
{
  return __rv__v_kslra16_u (ra, rb);
}
/* { dg-final { scan-assembler-times "kslra16.u" 1 } } */
/* { dg-final { scan-assembler-times "kslra16_u" 1 } } */
