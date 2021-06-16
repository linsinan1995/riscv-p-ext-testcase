/* ksub64 also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for ksub64 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64i_zpn_zpsf -mabi=lp64 -O0" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int64_t busk (int64_t ra, int64_t rb)
{
  return __rv_ksub64 (ra, rb);
}
/* { dg-final { scan-assembler-times "ksub64" 2 } } */
/* { dg-final { scan-assembler-times "builtin_riscv" 0 } } */
