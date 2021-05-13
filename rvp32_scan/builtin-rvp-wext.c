/* wext also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for wext instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options } "-march=rv32i_zpn_zpsf -mabi=ilp32 -O2" */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t txew (int64_t ra, uint32_t rb)
{
  return __rv__wext (ra, rb);
}
/* { dg-final { scan-assembler-times "wext" 2 } } */