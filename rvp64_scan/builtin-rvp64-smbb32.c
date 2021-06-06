/* smbb32 also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for smbb32 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64i_zpn_zprv_zpsf -mabi=lp64 -O0" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int32_t bbms (uint32_t ra, uint32_t rb)
{
  return __rv__smbb32 (ra, rb);
}

static __attribute__ ((noinline))
int32_t bbms_v (int32x2_t ra, int32x2_t rb)
{
  return __rv__v_smbb32 (ra, rb);
}
/* { dg-final { scan-assembler-times "smbb32" 3 } } */
/* { dg-final { scan-assembler-times "builtin_riscv" 0 } } */
