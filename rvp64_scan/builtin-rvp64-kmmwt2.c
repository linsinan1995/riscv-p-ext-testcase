/* kmmwt2 also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for kmmwt2 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zprv_zpsf -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int32_t twmmk (int32_t ra, int32_t rb)
{
  return __rv__kmmwt2 (ra, rb);
}

static __attribute__ ((noinline))
int32x2_t twmmk_v (int32x2_t ra, int16x4_t rb)
{
  return __rv__v_kmmwt2 (ra, rb);
}
/* { dg-final { scan-assembler-times "kmmwt2" 3 } } */
