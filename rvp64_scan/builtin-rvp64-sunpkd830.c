/* This is a test program for sunpkd830 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zpsf_zprv -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t dkpnus (uint32_t a)
{
  return __rv__sunpkd830 (a);
}

static __attribute__ ((noinline))
int16x4_t dkpnus_v (int8x8_t a)
{
  return __rv__v_sunpkd830 (a);
}
/* { dg-final { scan-assembler-times "sunpkd830" 3 } } */
