/* kmmawt2 also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for kmmawt2 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64i_zpn_zprv_zpsf -mabi=lp64 -O0" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int32_t twammk (int32_t rd, int32_t ra, int32_t rb)
{
  return __rv__kmmawt2 (rd, ra, rb);
}

static __attribute__ ((noinline))
int32x2_t twammk_v (int32x2_t rd, int32x2_t ra, int16x4_t rb)
{
  return __rv__v_kmmawt2 (rd, ra, rb);
}
/* { dg-final { scan-assembler-times "kmmawt2" 3 } } */
/* { dg-final { scan-assembler-times "builtin_riscv" 0 } } */
