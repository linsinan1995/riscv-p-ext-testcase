/* sll8 also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for sll8 instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gc_zpn -mabi=ilp32d -O0" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t lls (uint32_t ra, uint32_t rb)
{
  return __rv_sll8 (ra, rb);
}

static __attribute__ ((noinline))
uint8x4_t lls_v (uint8x4_t ra, uint32_t rb)
{
  return __rv_v_sll8 (ra, rb);
}
/* { dg-final { scan-assembler-times "sll8" 3 } } */
/* { dg-final { scan-assembler-times "builtin_riscv" 0 } } */
