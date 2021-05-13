/* This is a test program for sril16.u instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options } "-march=rv32i_zpn -mabi=ilp32 -O2" */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t u_61ilrs (uint32_t ra)
{
  return __rv__srl16_u (ra, 4);
}

static __attribute__ ((noinline))
uint16x2_t u_61ilrs_v (uint16x2_t ra)
{
  return __rv__v_srl16_u (ra, 4);
}
/* { dg-final { scan-assembler-times "srl16.u" 2 } } */
