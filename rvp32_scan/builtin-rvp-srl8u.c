/* This is a test program for srl8.u instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options } "-march=rv32i_zpn -mabi=ilp32 -O2" */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t u_8lrs (uint32_t ra, uint32_t rb)
{
  return __rv__srl8_u (ra, rb);
}

static __attribute__ ((noinline))
uint8x4_t u_8lrs_v (uint8x4_t ra, uint32_t rb)
{
  return __rv__v_srl8_u (ra, rb);
}
/* { dg-final { scan-assembler-times "srl8.u" 2 } } */
