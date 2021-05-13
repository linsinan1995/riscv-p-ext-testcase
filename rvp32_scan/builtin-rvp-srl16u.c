/* This is a test program for srl16.u instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options } "-march=rv32i_zpn -mabi=ilp32 -O2" */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t u_61lrs (uint32_t ra, uint32_t rb)
{
  return __rv__srl16_u (ra, rb);
}

static __attribute__ ((noinline))
uint16x2_t u_61lrs_v (uint16x2_t ra, uint32_t rb)
{
  return __rv__v_srl16_u (ra, rb);
}
/* { dg-final { scan-assembler-times "srl16.u" 2 } } */
