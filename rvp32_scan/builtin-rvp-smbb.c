/* This is a test program for smbb instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options } "-march=rv32i_zpn -mabi=ilp32 -O2" */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int32_t bbms (uint32_t ra, uint32_t rb)
{
  return __rv__smbb16 (ra, rb);
}

static __attribute__ ((noinline))
int bbms_v (int16x2_t ra, int16x2_t rb)
{
  return __rv__v_smbb16 (ra, rb);
}
/* { dg-final { scan-assembler-times "smbb16" 2 } } */
