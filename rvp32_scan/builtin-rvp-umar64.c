/* This is a test program for umar64 instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options } "-march=rv32i_zpn_zpsf -mabi=ilp32 -O2" */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint64_t ramu (uint64_t t,unsigned int a,unsigned int b)
{
  return __rv__umar64 (t, a, b);
}
/* { dg-final { scan-assembler-times "umar64" 2 } } */
