/* This is a test program for sra.u instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options } "-march=rv32i_zpn -mabi=ilp32 -O2" */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int uars (int ra, uint32_t rb)
{
  return __rv__sra_u (ra, rb);
}
/* { dg-final { scan-assembler-times "sra_u" 1 } } */
