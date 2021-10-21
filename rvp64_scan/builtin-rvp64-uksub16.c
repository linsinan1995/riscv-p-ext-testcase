/* uksub16 also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for sub16 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O0" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint64_t busku (uint64_t ra, uint64_t rb)
{
  return __rv_uksub16 (ra, rb);
}

static __attribute__ ((noinline))
uint16x4_t busku_v (uint16x4_t ra, uint16x4_t rb)
{
  return __rv_v_uksub16 (ra, rb);
}
/* { dg-final { scan-assembler-times "uksub16" 3 } } */
/* { dg-final { scan-assembler-times "builtin_riscv" 0 } } */
