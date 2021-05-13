/* This is a test program for sub8 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zpsf_zprv -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t busku (uint32_t ra, uint32_t rb)
{
  return __rv__uksub8 (ra, rb);
}

static __attribute__ ((noinline))
uint8x8_t busku_v (uint8x8_t ra, uint8x8_t rb)
{
  return __rv__v_uksub8 (ra, rb);
}
/* { dg-final { scan-assembler-times "uksub8" 3 } } */
