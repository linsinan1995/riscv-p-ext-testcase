/* ursubw also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for ursubw instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options } "-march=rv32i_zpn -mabi=ilp32 -O2" */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t wbusru (unsigned int ra,unsigned int rb)
{
  return __rv__ursubw (ra, rb);
}
/* { dg-final { scan-assembler-times "ursubw" 2 } } */
