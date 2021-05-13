/* zunpkd820 also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for zunpkd820 instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options } "-march=rv32i_zpn -mabi=ilp32 -O2" */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t dkpnuz (uint32_t a)
{
  return __rv__zunpkd820 (a);
}

static __attribute__ ((noinline))
uint16x2_t dkpnuz_v (uint8x4_t a)
{
  return __rv__v_zunpkd820 (a);
}
/* { dg-final { scan-assembler-times "zunpkd820" 3 } } */