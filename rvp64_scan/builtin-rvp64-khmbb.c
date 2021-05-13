/* This is a test program for khmbb instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zpsf_zprv -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int32_t bbmhk (int ra, int rb)
{
  return __rv__khmbb (ra, rb);
}

static __attribute__ ((noinline))
int32_t bbmhk_v (int16x4_t ra, int16x4_t rb)
{
  return __rv__v_khmbb (ra, rb);
}
/* { dg-final { scan-assembler-times "khmbb" 3 } } */
