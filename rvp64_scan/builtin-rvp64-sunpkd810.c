/* sunpkd810 also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for sunpkd810 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O0" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint64_t dkpnus (uint64_t a)
{
  return __rv_sunpkd810 (a);
}

static __attribute__ ((noinline))
int16x4_t dkpnus_v (int8x8_t a)
{
  return __rv_v_sunpkd810 (a);
}
/* { dg-final { scan-assembler-times "sunpkd810" 3 } } */
/* { dg-final { scan-assembler-times "builtin_riscv" 0 } } */
