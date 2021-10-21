/* wext also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for wext instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gc_zpn_zpsf -mabi=ilp32d -O0" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t txew (int64_t ra, uint32_t rb)
{
  return __rv_wext (ra, rb);
}
/* { dg-final { scan-assembler-times "wext" 2 } } */
/* { dg-final { scan-assembler-times "builtin_riscv" 0 } } */
