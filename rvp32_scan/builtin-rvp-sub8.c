/* sub8 also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for sub8 instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options } "-march=rv32i_zpn -mabi=ilp32 -O2" */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t bus (uint32_t ra, uint32_t rb)
{
  return __rv__sub8 (ra, rb);
}

static __attribute__ ((noinline))
uint8x4_t busu_v (uint8x4_t ra, uint8x4_t rb)
{
  return __rv__v_usub8 (ra, rb);
}

static __attribute__ ((noinline))
int8x4_t buss_v (int8x4_t ra, int8x4_t rb)
{
  return __rv__v_ssub8 (ra, rb);
}
/* { dg-final { scan-assembler-times "sub8" 4 } } */
