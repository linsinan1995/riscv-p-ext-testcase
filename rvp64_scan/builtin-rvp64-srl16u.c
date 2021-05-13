/* This is a test program for srl16.u instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zprv_zpsf -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t u_61lrs (uint32_t ra, uint32_t rb)
{
  return __rv__srl16_u (ra, rb);
}

static __attribute__ ((noinline))
uint16x4_t u_61lrs_v (uint16x4_t ra, uint32_t rb)
{
  return __rv__v_srl16_u (ra, rb);
}
/* { dg-final { scan-assembler-times "srl16_u" 2 } } */
