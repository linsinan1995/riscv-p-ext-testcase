/* crsa32 also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for crsa32 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zprv_zpsf -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t asrc (uint32_t ra, uint32_t rb)
{
  return __rv__crsa32 (ra, rb);
}

static __attribute__ ((noinline))
uint32x2_t asrcu_v (uint32x2_t ra, uint32x2_t rb)
{
  return __rv__v_ucrsa32 (ra, rb);
}

static __attribute__ ((noinline))
int32x2_t asrcs_v (int32x2_t ra, int32x2_t rb)
{
  return __rv__v_scrsa32 (ra, rb);
}
/* { dg-final { scan-assembler-times "crsa32" 4 } } */
