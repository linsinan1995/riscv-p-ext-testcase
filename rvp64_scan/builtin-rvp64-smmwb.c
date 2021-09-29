/* smmwb also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for smmwb instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64i_zpn_zpsf -mabi=lp64 -O0" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int64_t bwmms (int64_t ra, int64_t rb)
{
  return __rv_smmwb (ra, rb);
}

static __attribute__ ((noinline))
int32x2_t bwmms_v (int32x2_t ra, int16x4_t rb)
{
  return __rv_v_smmwb (ra, rb);
}
/* { dg-final { scan-assembler-times "smmwb" 3 } } */
/* { dg-final { scan-assembler-times "builtin_riscv" 0 } } */
