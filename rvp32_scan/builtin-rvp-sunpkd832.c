/* sunpkd832 also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for sunpkd832 instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options } "-march=rv32i_zpn -mabi=ilp32 -O2" */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t dkpnus (uint32_t a)
{
  return __rv__sunpkd832 (a);
}

static __attribute__ ((noinline))
int16x2_t dkpnus_v (int8x4_t a)
{
  return __rv__v_sunpkd832 (a);
}
/* { dg-final { scan-assembler-times "sunpkd832" 3 } } */