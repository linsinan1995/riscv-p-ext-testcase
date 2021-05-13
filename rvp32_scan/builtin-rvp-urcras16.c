/* This is a test program for urcras16 instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options } "-march=rv32i_zpn -mabi=ilp32 -O2" */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t sarcru (uint32_t ra, uint32_t rb)
{
  return __rv__urcras16 (ra, rb);
}

static __attribute__ ((noinline))
uint16x2_t sarcru_v (uint16x2_t ra, uint16x2_t rb)
{
  return __rv__v_urcras16 (ra, rb);
}
/* { dg-final { scan-assembler-times "urcras16" 3 } } */
