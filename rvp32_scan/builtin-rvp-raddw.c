/* raddw also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for raddw instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options } "-march=rv32i_zpn -mabi=ilp32 -O2" */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int32_t wddar (int32_t ra, int32_t rb)
{
  return __rv__raddw (ra, rb);
}
/* { dg-final { scan-assembler-times "raddw" 2 } } */
