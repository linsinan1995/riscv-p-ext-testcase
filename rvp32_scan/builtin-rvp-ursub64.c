/* ursub64 also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for ursub64 instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32i_zpn_zpsf -mabi=ilp32 -O0" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint64_t busru (uint64_t ra, uint64_t rb)
{
  return __rv_ursub64 (ra, rb);
}
/* { dg-final { scan-assembler-times "ursub64" 2 } } */
/* { dg-final { scan-assembler-times "builtin_riscv" 0 } } */
