/* kdmbt16 also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for kdmbt16 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64i_zpn_zprv_zpsf -mabi=lp64 -O0" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int32_t tbmdk (uint32_t ra, uint32_t rb)
{
  return __rv__kdmbt16 (ra, rb);
}

static __attribute__ ((noinline))
int32x2_t tbmdk_v (int16x4_t ra, int16x4_t rb)
{
  return __rv__v_kdmbt16 (ra, rb);
}
/* { dg-final { scan-assembler-times "kdmbt16" 3 } } */
/* { dg-final { scan-assembler-times "builtin_riscv" 0 } } */
