/* smmwt also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for smmwt instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zprv_zpsf -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int32_t twmms (int32_t ra, int32_t rb)
{
  return __rv__smmwt (ra, rb);
}

static __attribute__ ((noinline))
int32x2_t twmms_v (int32x2_t ra, int16x4_t rb)
{
  return __rv__v_smmwt (ra, rb);
}
/* { dg-final { scan-assembler-times "smmwt" 3 } } */
