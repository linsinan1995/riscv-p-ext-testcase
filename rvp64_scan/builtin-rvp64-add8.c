/* add8 also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for add8 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64i_zpn_zpsf -mabi=lp64 -O0" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint64_t dda (uint64_t ra, uint64_t rb)
{
  return __rv_add8 (ra, rb);
}

static __attribute__ ((noinline))
uint8x8_t ddau_v (uint8x8_t ra, uint8x8_t rb)
{
  return __rv_v_uadd8 (ra, rb);
}

static __attribute__ ((noinline))
int8x8_t ddas_v (int8x8_t ra, int8x8_t rb)
{
  return __rv_v_sadd8 (ra, rb);
}
/* { dg-final { scan-assembler-times "add8" 4 } } */
/* { dg-final { scan-assembler-times "builtin_riscv" 0 } } */
