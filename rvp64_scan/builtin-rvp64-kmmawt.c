/* This is a test program for kmmawt instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zpsf_zprv -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int32_t twammk (int32_t rd, int32_t ra, int32_t rb)
{
  return __rv__kmmawt (rd, ra, rb);
}

static __attribute__ ((noinline))
int32x2_t twammk_v (int32x2_t rd, int32x2_t ra, int16x4_t rb)
{
  return __rv__v_kmmawt (rd, ra, rb);
}
/* { dg-final { scan-assembler-times "kmmawt" 3 } } */
