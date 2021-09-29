/* umul8 also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for umul8 instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32i_zpn_zpsf -mabi=ilp32 -O0" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint64_t lumu (uint32_t ra, uint32_t rb)
{
  return __rv_umul8 (ra, rb);
}

static __attribute__ ((noinline))
uint16x4_t lumu_v (uint8x4_t ra, uint8x4_t rb)
{
  return __rv_v_umul8 (ra, rb);
}
/* { dg-final { scan-assembler-times "umul8" 3 } } */
/* { dg-final { scan-assembler-times "builtin_riscv" 0 } } */
