/* smal also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for smal instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64i_zpn_zprv_zpsf -mabi=lp64 -O0" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int64_t lams (int64_t ra, int64_t rb)
{
  return __rv__smal (ra, rb);
}

static __attribute__ ((noinline))
int64_t lams_v (int64_t ra, int16x4_t rb)
{
  return __rv__v_smal (ra, rb);
}
/* { dg-final { scan-assembler-times "smal" 3 } } */
/* { dg-final { scan-assembler-times "builtin_riscv" 0 } } */
