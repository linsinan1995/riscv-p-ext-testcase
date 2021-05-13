/* This is a test program for sra32u instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zprv_zpsf -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t u23ars (uint32_t ra, uint32_t rb)
{
  return __rv__sra32_u (ra, rb);
}

static __attribute__ ((noinline))
int32x2_t u23ars_v (int32x2_t ra, uint32_t rb)
{
  return __rv__v_sra32_u (ra, rb);
}
/* { dg-final { scan-assembler-times "sra32_u" 2 } } */
