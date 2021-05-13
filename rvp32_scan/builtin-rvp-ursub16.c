/* ursub16 also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for ursub16 instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options } "-march=rv32i_zpn -mabi=ilp32 -O2" */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t busru (uint32_t ra, uint32_t rb)
{
  return __rv__ursub16 (ra, rb);
}

static __attribute__ ((noinline))
uint16x2_t busru_v (uint16x2_t ra, uint16x2_t rb)
{
  return __rv__v_ursub16 (ra, rb);
}
/* { dg-final { scan-assembler-times "ursub16" 3 } } */
