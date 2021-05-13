/* This is a test program for srai16.u instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options } "-march=rv32i_zpn -mabi=ilp32 -O2" */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t u61iars (uint32_t ra)
{
  return __rv__sra16_u (ra, 4);
}

static __attribute__ ((noinline))
int16x2_t u61iars_v (int16x2_t ra)
{
  return __rv__v_sra16_u (ra, 4);
}
/* { dg-final { scan-assembler-times "sra16_u" 2 } } */
