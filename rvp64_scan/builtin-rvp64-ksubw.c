/* ksubw also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for ksubw instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64i_zpn_zpsf -mabi=lp64 -O0" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int wbusk (int ra, int rb)
{
  return __rv_ksubw (ra, rb);
}
/* { dg-final { scan-assembler-times "ksubw" 2 } } */
/* { dg-final { scan-assembler-times "builtin_riscv" 0 } } */
