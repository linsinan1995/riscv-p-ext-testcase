/* This is a test program for umulx16 instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options } "-march=rv32i_zpn -mabi=ilp32 -O2" */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint64_t xlumu (unsigned long ra, unsigned long rb)
{
  return __rv__umulx16 (ra, rb);
}

static __attribute__ ((noinline))
uint32x2_t xlumu_v (uint16x2_t ra, uint16x2_t rb)
{
  return __rv__v_umulx16 (ra, rb);
}
/* { dg-final { scan-assembler-times "umulx16" 3 } } */
