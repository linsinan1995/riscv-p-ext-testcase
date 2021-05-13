/* This is a test program for smal instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zpsf_zprv -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int64_t lams (int64_t ra, unsigned long rb)
{
  return __rv__smal (ra, rb);
}

static __attribute__ ((noinline))
int64_t lams_v (int64_t ra, int16x4_t rb)
{
  return __rv__v_smal (ra, rb);
}
/* { dg-final { scan-assembler-times "smal" 3 } } */
