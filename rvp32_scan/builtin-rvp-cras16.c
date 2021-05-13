/* cras16 also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for cras16 instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options } "-march=rv32i_zpn -mabi=ilp32 -O2" */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t sarc (uint32_t ra, uint32_t rb)
{
  return __rv__cras16 (ra, rb);
}

static __attribute__ ((noinline))
uint16x2_t sarcu_v (uint16x2_t ra, uint16x2_t rb)
{
  return __rv__v_ucras16 (ra, rb);
}

static __attribute__ ((noinline))
int16x2_t sarcs_v (int16x2_t ra, int16x2_t rb)
{
  return __rv__v_scras16 (ra, rb);
}
/* { dg-final { scan-assembler-times "cras16" 2 } } */
/* { dg-final { scan-assembler-times "ucras16" 1 } } */
/* { dg-final { scan-assembler-times "scras16" 1 } } */
