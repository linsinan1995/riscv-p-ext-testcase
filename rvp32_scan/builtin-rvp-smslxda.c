/* smslxda also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for smslxda instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options } "-march=rv32i_zpn_zpsf -mabi=ilp32 -O2" */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int64_t adxlsms (int64_t rt, unsigned long ra, unsigned long rb)
{
  return __rv__smslxda (rt, ra, rb);
}

static __attribute__ ((noinline))
int64_t adxlsms_v (int64_t rt, int16x2_t ra, int16x2_t rb)
{
  return __rv__v_smslxda (rt, ra, rb);
}
/* { dg-final { scan-assembler-times "smslxda" 3 } } */
