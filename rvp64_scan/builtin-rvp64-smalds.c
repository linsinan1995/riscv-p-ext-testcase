/* smalds also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for smalds instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zprv_zpsf -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int64_t sdlams (int64_t t, unsigned long a, unsigned long b)
{
  return __rv__smalds (t, a, b);
}

static __attribute__ ((noinline))
int64_t sdlams_v (int64_t t, int16x4_t a, int16x4_t b)
{
  return __rv__v_smalds (t, a, b);
}

/* { dg-final { scan-assembler-times "smalds" 3 } } */
