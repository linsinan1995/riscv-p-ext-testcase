/* kwmmul also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for kwmmul instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O0" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int64_t lummwk (int64_t ra, int64_t rb)
{
  return __rv_kwmmul (ra, rb);
}
/* { dg-final { scan-assembler-times "kwmmul" 2 } } */
/* { dg-final { scan-assembler-times "builtin_riscv" 0 } } */
