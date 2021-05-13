/* This is a test program for smalda instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options } "-march=rv32i_zpn_zpsf -mabi=ilp32 -O2" */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int64_t adlams (int64_t t, unsigned long a, unsigned long b)
{
  return __rv__smalda (t, a, b);
}

static __attribute__ ((noinline))
int64_t adlams_v (int64_t t, int16x2_t a, int16x2_t b)
{
  return __rv__v_smalda (t, a, b);
}

/* { dg-final { scan-assembler-times "smalda" 3 } } */
