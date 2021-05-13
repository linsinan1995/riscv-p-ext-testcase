/* This is a test program for sra32 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zpsf_zprv -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t ars (uint32_t ra, uint32_t rb)
{
  return __rv__sra32 (ra, rb);
}

static __attribute__ ((noinline))
int32x2_t ars_v (int32x2_t ra, uint32_t rb)
{
  return __rv__v_sra32 (ra, rb);
}
/* { dg-final { scan-assembler-times "sra32" 3 } } */
