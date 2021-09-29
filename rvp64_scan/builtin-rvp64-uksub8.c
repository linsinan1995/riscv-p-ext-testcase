/* uksub8 also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for sub8 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64i_zpn_zpsf -mabi=lp64 -O0" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint64_t busku (uint64_t ra, uint64_t rb)
{
  return __rv_uksub8 (ra, rb);
}

static __attribute__ ((noinline))
uint8x8_t busku_v (uint8x8_t ra, uint8x8_t rb)
{
  return __rv_v_uksub8 (ra, rb);
}
/* { dg-final { scan-assembler-times "uksub8" 3 } } */
/* { dg-final { scan-assembler-times "builtin_riscv" 0 } } */
