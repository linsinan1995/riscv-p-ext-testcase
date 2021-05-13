/* This is a test program for srai32 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zprv_zpsf -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t iars (uint32_t ra)
{
  return __rv__sra32 (ra, 4);
}

static __attribute__ ((noinline))
int32x2_t iars_v (int32x2_t ra)
{
  return __rv__v_sra32 (ra, 4);
}
/* { dg-final { scan-assembler-times "sra32" 2 } } */