/* This is a test program for srai16 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64i_zpn_zprv_zpsf -mabi=lp64 -O0" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t iars (uint32_t ra)
{
  return __rv__sra16 (ra, 4);
}

static __attribute__ ((noinline))
int16x4_t iars_v (int16x4_t ra)
{
  return __rv__v_sra16 (ra, 4);
}
/* { dg-final { scan-assembler-times "sra16" 2 } } */
/* { dg-final { scan-assembler-times "builtin_riscv" 0 } } */
