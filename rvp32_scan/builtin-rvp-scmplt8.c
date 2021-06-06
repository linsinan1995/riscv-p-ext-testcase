/* scmplt8 also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for scmplt8 instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32i_zpn -mabi=ilp32 -O0" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t tlpmcs (uint32_t ra, uint32_t rb)
{
  return __rv__scmplt8 (ra, rb);
}

static __attribute__ ((noinline))
uint8x4_t tlpmcs_v (int8x4_t ra, int8x4_t rb)
{
  return __rv__v_scmplt8 (ra, rb);
}
/* { dg-final { scan-assembler-times "scmplt8" 3 } } */
/* { dg-final { scan-assembler-times "builtin_riscv" 0 } } */
