/* smal also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for smal instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32i_zpn_zpsf -mabi=ilp32 -O0" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int64_t lams (int64_t ra, uint32_t rb)
{
  return __rv__smal (ra, rb);
}

static __attribute__ ((noinline))
int64_t lams_v (int64_t ra, int16x2_t rb)
{
  return __rv__v_smal (ra, rb);
}
/* { dg-final { scan-assembler-times "smal" 3 } } */
/* { dg-final { scan-assembler-times "builtin_riscv" 0 } } */
