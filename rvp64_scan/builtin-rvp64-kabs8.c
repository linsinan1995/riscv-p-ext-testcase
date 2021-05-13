/* This is a test program for kabs8 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zpsf_zprv -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t sbak (uint32_t ra)
{
  return __rv__kabs8 (ra);
}

static __attribute__ ((noinline))
int8x8_t sbak_v (int8x8_t ra)
{
  return __rv__v_kabs8 (ra);
}
/* { dg-final { scan-assembler-times "kabs8" 3 } } */
