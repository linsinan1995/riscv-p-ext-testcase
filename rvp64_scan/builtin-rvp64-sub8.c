/* sub8 also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for sub8 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zprv_zpsf -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t bus (uint32_t ra, uint32_t rb)
{
  return __rv__sub8 (ra, rb);
}

static __attribute__ ((noinline))
uint8x8_t busu_v (uint8x8_t ra, uint8x8_t rb)
{
  return __rv__v_usub8 (ra, rb);
}

static __attribute__ ((noinline))
int8x8_t buss_v (int8x8_t ra, int8x8_t rb)
{
  return __rv__v_ssub8 (ra, rb);
}
/* { dg-final { scan-assembler-times "sub8" 2 } } */
/* { dg-final { scan-assembler-times "usub8" 1 } } */
/* { dg-final { scan-assembler-times "ssub8" 1 } } */
