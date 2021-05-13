/* This is a test program for wsbh instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options } "-march=rv32i_zpn -mabi=ilp32 -O2" */
/* { dg-options "-O0" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t paws (uint32_t a)
{
  return __rv__swap8 (a);
}
/* { dg-final { scan-assembler-times "swap8" 2 } } */
