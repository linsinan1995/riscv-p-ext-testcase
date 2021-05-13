/* smdrs also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for smdrs instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options } "-march=rv32i_zpn -mabi=ilp32 -O2" */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int32_t srdms (uint32_t ra, uint32_t rb)
{
  return __rv__smdrs (ra, rb);
}

static __attribute__ ((noinline))
int32_t srdms_v (int16x2_t ra, int16x2_t rb)
{
  return __rv__v_smdrs (ra, rb);
}
/* { dg-final { scan-assembler-times "smdrs" 3 } } */
