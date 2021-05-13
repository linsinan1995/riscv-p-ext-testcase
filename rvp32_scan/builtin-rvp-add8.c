/* This is a test program for add8 instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options } "-march=rv32i_zpn -mabi=ilp32 -O2" */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t dda (uint32_t ra, uint32_t rb)
{
  return __rv__add8 (ra, rb);
}

static __attribute__ ((noinline))
uint8x4_t ddau_v (uint8x4_t ra, uint8x4_t rb)
{
  return __rv__v_uadd8 (ra, rb);
}

static __attribute__ ((noinline))
int8x4_t ddas_v (int8x4_t ra, int8x4_t rb)
{
  return __rv__v_sadd8 (ra, rb);
}
/* { dg-final { scan-assembler-times "add8" 4 } } */
