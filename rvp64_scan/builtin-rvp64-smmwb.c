/* smmwb also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for smmwb instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64i_zpn_zprv_zpsf -mabi=lp64 -O0" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int32_t bwmms (int32_t ra, int32_t rb)
{
  return __rv__smmwb (ra, rb);
}

static __attribute__ ((noinline))
int32x2_t bwmms_v (int32x2_t ra, int16x4_t rb)
{
  return __rv__v_smmwb (ra, rb);
}
/* { dg-final { scan-assembler-times "smmwb" 3 } } */
/* { dg-final { scan-assembler-times "builtin_riscv" 0 } } */
