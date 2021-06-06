/* kslraw also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for kslraw instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64i_zpn_zprv_zpsf -mabi=lp64 -O0" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int warlsk (int ra, int rb)
{
  return __rv__kslraw (ra, rb);
}
/* { dg-final { scan-assembler-times "kslraw" 2 } } */
/* { dg-final { scan-assembler-times "builtin_riscv" 0 } } */
