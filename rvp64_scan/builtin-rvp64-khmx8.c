/* This is a test program for khmx8 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zpsf_zprv -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t xmhk (uint32_t ra, uint32_t rb)
{
  return __rv__khmx8 (ra, rb);
}

static __attribute__ ((noinline))
int8x8_t xmhk_v (int8x8_t ra, int8x8_t rb)
{
  return __rv__v_khmx8 (ra, rb);
}
/* { dg-final { scan-assembler-times "khmx8" 3 } } */
