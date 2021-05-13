/* This is a test program for smslda instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options } "-march=rv32i_zpn -mabi=ilp32 -O2" */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int64_t adlsms (int64_t rt, unsigned long ra, unsigned long rb)
{
  return __rv__smslda (rt, ra, rb);
}

static __attribute__ ((noinline))
int64_t adlsms_v (int64_t rt, int16x2_t ra, int16x2_t rb)
{
  return __rv__v_smslda (rt, ra, rb);
}
/* { dg-final { scan-assembler-times "smslda" 3 } } */
