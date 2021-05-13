/* smsr64 also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for smsr64 instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options } "-march=rv32i_zpn_zpsf -mabi=ilp32 -O2" */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int64_t rsms (int64_t t, int a, int b)
{
  return __rv__smsr64 (t, a, b);
}
/* { dg-final { scan-assembler-times "smsr64" 2 } } */
