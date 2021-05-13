/* uclip8 also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for add8 instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options } "-march=rv32i_zpn -mabi=ilp32 -O2" */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t pilcu (uint32_t ra)
{
  return __rv__uclip8 (ra, 2);
}

static __attribute__ ((noinline))
uint8x4_t pilcu_v (uint8x4_t ra)
{
  return __rv__v_uclip8 (ra, 3);
}
/* { dg-final { scan-assembler-times "uclip8" 3 } } */
