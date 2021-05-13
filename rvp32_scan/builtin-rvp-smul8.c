/* smul8 also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for smul8 instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options } "-march=rv32i_zpn_zpsf -mabi=ilp32 -O2" */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint64_t lums (uint32_t ra, uint32_t rb)
{
  return __rv__smul8 (ra, rb);
}

static __attribute__ ((noinline))
int16x4_t lums_v (int8x4_t ra, int8x4_t rb)
{
  return __rv__v_smul8 (ra, rb);
}
/* { dg-final { scan-assembler-times "smul8" 3 } } */
