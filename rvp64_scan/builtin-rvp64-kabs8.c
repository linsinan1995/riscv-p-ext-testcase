/* kabs8 also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for kabs8 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64i_zpn_zprv_zpsf -mabi=lp64 -O0" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t sbak (uint32_t ra)
{
  return __rv__kabs8 (ra);
}

static __attribute__ ((noinline))
int8x8_t sbak_v (int8x8_t ra)
{
  return __rv__v_kabs8 (ra);
}
/* { dg-final { scan-assembler-times "kabs8" 3 } } */
/* { dg-final { scan-assembler-times "builtin_riscv" 0 } } */
