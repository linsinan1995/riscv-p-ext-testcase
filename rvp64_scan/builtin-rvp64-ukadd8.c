/* ukadd8 also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for add8 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64i_zpn_zprv_zpsf -mabi=lp64 -O0" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t ddaku (uint32_t ra, uint32_t rb)
{
  return __rv__ukadd8 (ra, rb);
}

static __attribute__ ((noinline))
uint8x8_t ddaku_v (uint8x8_t ra, uint8x8_t rb)
{
  return __rv__v_ukadd8 (ra, rb);
}
/* { dg-final { scan-assembler-times "ukadd8" 3 } } */
/* { dg-final { scan-assembler-times "builtin_riscv" 0 } } */
