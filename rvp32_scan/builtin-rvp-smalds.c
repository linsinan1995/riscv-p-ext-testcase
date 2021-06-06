/* smalds also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for smalds instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32i_zpn_zpsf -mabi=ilp32 -O0" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int64_t sdlams (int64_t t, uint32_t a, uint32_t b)
{
  return __rv__smalds (t, a, b);
}

static __attribute__ ((noinline))
int64_t sdlams_v (int64_t t, int16x2_t a, int16x2_t b)
{
  return __rv__v_smalds (t, a, b);
}

/* { dg-final { scan-assembler-times "smalds" 3 } } */
/* { dg-final { scan-assembler-times "builtin_riscv" 0 } } */
