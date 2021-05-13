/* This is a test program for srl32u instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zpsf_zprv -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t u23lrs (uint32_t ra, uint32_t rb)
{
  return __rv__srl32_u (ra, rb);
}

static __attribute__ ((noinline))
uint32x2_t u23lrs_v (uint32x2_t ra, uint32_t rb)
{
  return __rv__v_srl32_u (ra, rb);
}
/* { dg-final { scan-assembler-times "srl32_u" 2 } } */
