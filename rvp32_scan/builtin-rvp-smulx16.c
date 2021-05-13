/* This is a test program for smulx16 instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options } "-march=rv32i_zpn_zpsf -mabi=ilp32 -O2" */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint64_t xlums (unsigned long ra, unsigned long rb)
{
  return __rv__smulx16 (ra, rb);
}

static __attribute__ ((noinline))
int32x2_t xlums_v (int16x2_t ra, int16x2_t rb)
{
  return __rv__v_smulx16 (ra, rb);
}
/* { dg-final { scan-assembler-times "smulx16" 3 } } */
