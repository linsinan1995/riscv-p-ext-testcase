/* This is a test program for smaldrs instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options } "-march=rv32i_zpn_zpsf -mabi=ilp32 -O2" */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int64_t srdlams (int64_t t, unsigned long a, unsigned long b)
{
  return __rv__smaldrs (t, a, b);
}

static __attribute__ ((noinline))
int64_t srdlams_v (int64_t t, int16x2_t a, int16x2_t b)
{
  return __rv__v_smaldrs (t, a, b);
}

/* { dg-final { scan-assembler-times "smaldrs" 3 } } */
