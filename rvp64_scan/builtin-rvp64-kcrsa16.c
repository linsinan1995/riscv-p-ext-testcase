/* kcrsa16 also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for crsa16 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64i_zpn_zpsf -mabi=lp64 -O0" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint64_t asrck (uint64_t ra, uint64_t rb)
{
  return __rv_kcrsa16 (ra, rb);
}

static __attribute__ ((noinline))
int16x4_t asrck_v (int16x4_t ra, int16x4_t rb)
{
  return __rv_v_kcrsa16 (ra, rb);
}
/* { dg-final { scan-assembler-times "kcrsa16" 3 } } */
/* { dg-final { scan-assembler-times "builtin_riscv" 0 } } */
