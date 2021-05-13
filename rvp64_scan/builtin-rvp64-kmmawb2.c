/* kmmawb2 also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for kmmawb2 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zprv_zpsf -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int32_t bwammk (int32_t rd, int32_t ra, uint32_t rb)
{
  return __rv__kmmawb2 (rd, ra, rb);
}

static __attribute__ ((noinline))
int32x2_t bwammk_v (int32x2_t rd, int32x2_t ra, int16x4_t rb)
{
  return __rv__v_kmmawb2 (rd, ra, rb);
}
/* { dg-final { scan-assembler-times "kmmawb2" 3 } } */
