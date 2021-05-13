/* This is a test program for sunpkd830 instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options } "-march=rv32i_zpn -mabi=ilp32 -O2" */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t dkpnus (uint32_t a)
{
  return __rv__sunpkd830 (a);
}

static __attribute__ ((noinline))
int16x2_t dkpnus_v (int8x4_t a)
{
  return __rv__v_sunpkd830 (a);
}
/* { dg-final { scan-assembler-times "sunpkd830" 3 } } */
