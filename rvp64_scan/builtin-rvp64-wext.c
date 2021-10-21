/* wext also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for wext instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O0" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int64_t txew (uint64_t ra, uint32_t rb)
{
  return __rv_wext (ra, rb);
}
/* { dg-final { scan-assembler-times "wext" 2 } } */
/* { dg-final { scan-assembler-times "builtin_riscv" 0 } } */
