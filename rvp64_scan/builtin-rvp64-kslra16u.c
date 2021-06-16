/* This is a test program for kslra16 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64i_zpn_zpsf -mabi=lp64 -O0" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint64_t u61arlsk (uint64_t ra, int32_t rb)
{
  return __rv_kslra16_u (ra, rb);
}

static __attribute__ ((noinline))
int16x4_t u61arlsk_v (int16x4_t ra, int32_t rb)
{
  return __rv_v_kslra16_u (ra, rb);
}
/* { dg-final { scan-assembler-times "kslra16.u" 2 } } */
/* { dg-final { scan-assembler-times "builtin_riscv" 0 } } */
