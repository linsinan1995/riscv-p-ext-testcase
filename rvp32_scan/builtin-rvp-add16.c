/* add16 also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for add16 instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options } "-march=rv32i_zpn -mabi=ilp32 -O2" */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t dda (uint32_t ra, uint32_t rb)
{
  return __rv__add16 (ra, rb);
}

static __attribute__ ((noinline))
uint16x2_t ddau_v (uint16x2_t ra, uint16x2_t rb)
{
  return __rv__v_uadd16 (ra, rb);
}

static __attribute__ ((noinline))
int16x2_t ddas_v (int16x2_t ra, int16x2_t rb)
{
  return __rv__v_sadd16 (ra, rb);
}
/* { dg-final { scan-assembler-times "add16" 2 } } */
/* { dg-final { scan-assembler-times "uadd16" 1 } } */
/* { dg-final { scan-assembler-times "sadd16" 1 } } */
