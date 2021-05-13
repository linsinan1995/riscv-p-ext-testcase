/* crsa16 also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for crsa16 instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options } "-march=rv32i_zpn -mabi=ilp32 -O2" */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t asrc (uint32_t ra, uint32_t rb)
{
  return __rv__crsa16 (ra, rb);
}

static __attribute__ ((noinline))
uint16x2_t asrcu_v (uint16x2_t ra, uint16x2_t rb)
{
  return __rv__v_ucrsa16 (ra, rb);
}

static __attribute__ ((noinline))
int16x2_t asrcs_v (int16x2_t ra, int16x2_t rb)
{
  return __rv__v_scrsa16 (ra, rb);
}
/* { dg-final { scan-assembler-times "crsa16" 4 } } */
