/* smbt32 also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for smbt32 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zprv_zpsf -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int32_t tbms (uint32_t ra, uint32_t rb)
{
  return __rv__smbt32 (ra, rb);
}

static __attribute__ ((noinline))
int32_t tbms_v (int32x2_t ra, int32x2_t rb)
{
  return __rv__v_smbt32 (ra, rb);
}
/* { dg-final { scan-assembler-times "smbt32" 3 } } */
