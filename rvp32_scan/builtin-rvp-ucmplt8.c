/* ucmplt8 also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for ucmplt8 instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32i_zpn -mabi=ilp32 -O0" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t tlpmcu (uint32_t ra, uint32_t rb)
{
  return __rv__ucmplt8 (ra, rb);
}

static __attribute__ ((noinline))
uint8x4_t tlpmcu_v (uint8x4_t ra, uint8x4_t rb)
{
  return __rv__v_ucmplt8 (ra, rb);
}
/* { dg-final { scan-assembler-times "ucmplt8" 3 } } */
/* { dg-final { scan-assembler-times "builtin_riscv" 0 } } */
