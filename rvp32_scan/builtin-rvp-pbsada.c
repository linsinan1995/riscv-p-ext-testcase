/* This is a test program for pbsada instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options } "-march=rv32i_zpn -mabi=ilp32 -O2" */
/* { dg-options "-O1" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t adasbp (uint32_t ra, uint32_t rb, uint32_t rc)
{
  return __rv__pbsada (ra, rb, rc);
}
/* { dg-final { scan-assembler-times "pbsada" 2 } } */
