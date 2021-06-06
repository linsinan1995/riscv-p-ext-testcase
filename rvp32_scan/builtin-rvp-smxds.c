/* smxds also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for smxds instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32i_zpn -mabi=ilp32 -O0" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int32_t sdxms (uint32_t ra, uint32_t rb)
{
  return __rv__smxds (ra, rb);
}

static __attribute__ ((noinline))
int32_t sdxms_v (int16x2_t ra, int16x2_t rb)
{
  return __rv__v_smxds (ra, rb);
}
/* { dg-final { scan-assembler-times "smxds" 3 } } */
/* { dg-final { scan-assembler-times "builtin_riscv" 0 } } */
