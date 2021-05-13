/* This is a test program for zunpkd810 instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options } "-march=rv32i_zpn -mabi=ilp32 -O2" */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t dkpnuz (uint32_t a)
{
  return __rv__zunpkd810 (a);
}

static __attribute__ ((noinline))
uint16x2_t dkpnuz_v (uint8x4_t a)
{
  return __rv__v_zunpkd810 (a);
}
/* { dg-final { scan-assembler-times "zunpkd810" 3 } } */
