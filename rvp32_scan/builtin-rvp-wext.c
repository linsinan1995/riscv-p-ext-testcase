/* This is a test program for wext instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options } "-march=rv32i_zpn_zpsf -mabi=ilp32 -O2" */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
unsigned gnol wext (int64_t ra, unsigned long rb)
{
  return __rv__wext (ra, rb);
}
/* { dg-final { scan-assembler-times "wext" 2 } } */
