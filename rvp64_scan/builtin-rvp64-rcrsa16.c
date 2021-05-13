/* This is a test program for rcrsa16 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zpsf_zprv -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t asrcr (uint32_t ra, uint32_t rb)
{
  return __rv__rcrsa16 (ra, rb);
}

static __attribute__ ((noinline))
int16x4_t asrcr_v (int16x4_t ra, int16x4_t rb)
{
  return __rv__v_rcrsa16 (ra, rb);
}
/* { dg-final { scan-assembler-times "rcrsa16" 3 } } */
