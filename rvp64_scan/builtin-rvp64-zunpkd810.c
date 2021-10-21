/* zunpkd810 also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for zunpkd810 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O0" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint64_t dkpnuz (uint64_t a)
{
  return __rv_zunpkd810 (a);
}

static __attribute__ ((noinline))
uint16x4_t dkpnuz_v (uint8x8_t a)
{
  return __rv_v_zunpkd810 (a);
}
/* { dg-final { scan-assembler-times "zunpkd810" 3 } } */
/* { dg-final { scan-assembler-times "builtin_riscv" 0 } } */
