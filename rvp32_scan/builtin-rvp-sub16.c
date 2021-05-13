/* This is a test program for sub16 instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options } "-march=rv32i_zpn -mabi=ilp32 -O2" */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t bus (uint32_t ra, uint32_t rb)
{
  return __rv__sub16 (ra, rb);
}

static __attribute__ ((noinline))
uint16x2_t busu_v (uint16x2_t ra, uint16x2_t rb)
{
  return __rv__v_usub16 (ra, rb);
}

static __attribute__ ((noinline))
int16x2_t buss_v (int16x2_t ra, int16x2_t rb)
{
  return __rv__v_ssub16 (ra, rb);
}
/* { dg-final { scan-assembler-times "sub16" 4 } } */
