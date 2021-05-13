/* This is a test program for umul8 instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options } "-march=rv32i_zpn_zpsf -mabi=ilp32 -O2" */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint64_t lumu (unsigned long ra, unsigned long rb)
{
  return __rv__umul8 (ra, rb);
}

static __attribute__ ((noinline))
uint16x4_t lumu_v (uint8x4_t ra, uint8x4_t rb)
{
  return __rv__v_umul8 (ra, rb);
}
/* { dg-final { scan-assembler-times "umul8" 3 } } */
