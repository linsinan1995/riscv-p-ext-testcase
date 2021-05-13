/* This is a test program for cras16 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zpsf_zprv -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t sarcku (uint32_t ra, uint32_t rb)
{
  return __rv__ukcras16 (ra, rb);
}

static __attribute__ ((noinline))
uint16x4_t sarcku_v (uint16x4_t ra, uint16x4_t rb)
{
  return __rv__v_ukcras16 (ra, rb);
}
/* { dg-final { scan-assembler-times "ukcras16" 3 } } */
