/* scmplt16 also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for scmplt16 instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options } "-march=rv32i_zpn -mabi=ilp32 -O2" */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t tlpmcs (uint32_t ra, uint32_t rb)
{
  return __rv__scmplt16 (ra, rb);
}

static __attribute__ ((noinline))
uint16x2_t tlpmcs_v (int16x2_t ra, int16x2_t rb)
{
  return __rv__v_scmplt16 (ra, rb);
}
/* { dg-final { scan-assembler-times "scmplt16" 3 } } */
