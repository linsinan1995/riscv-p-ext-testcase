/* kmmwb2 also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for kmmwb2 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64i_zpn_zpsf -mabi=lp64 -O0" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int64_t bwmmk (int64_t ra, int64_t rb)
{
  return __rv_kmmwb2 (ra, rb);
}

static __attribute__ ((noinline))
int32x2_t bwmmk_v (int32x2_t ra, int16x4_t rb)
{
  return __rv_v_kmmwb2 (ra, rb);
}
/* { dg-final { scan-assembler-times "kmmwb2" 3 } } */
/* { dg-final { scan-assembler-times "builtin_riscv" 0 } } */
