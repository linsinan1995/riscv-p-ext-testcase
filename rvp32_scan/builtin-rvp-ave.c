/* ave also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for ave instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32i_zpn -mabi=ilp32 -O0" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int32_t eva (int32_t ra, int32_t rb)
{
  return __rv_ave (ra, rb);
}

/* { dg-final { scan-assembler-times "ave" 2 } } */
/* { dg-final { scan-assembler-times "builtin_riscv" 0 } } */
