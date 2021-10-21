/* ucmplt16 also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for ucmplt16 instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gc_zpn -mabi=ilp32d -O0" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t tlpmcu (uint32_t ra, uint32_t rb)
{
  return __rv_ucmplt16 (ra, rb);
}

static __attribute__ ((noinline))
uint16x2_t tlpmcu_v (uint16x2_t ra, uint16x2_t rb)
{
  return __rv_v_ucmplt16 (ra, rb);
}
/* { dg-final { scan-assembler-times "ucmplt16" 3 } } */
/* { dg-final { scan-assembler-times "builtin_riscv" 0 } } */
