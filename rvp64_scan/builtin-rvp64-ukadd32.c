/* ukadd32 also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for ukadd32 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O0" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint64_t ddaku (uint64_t ra, uint64_t rb)
{
  return __rv_ukadd32 (ra, rb);
}

static __attribute__ ((noinline))
uint32x2_t ddaku_v (uint32x2_t ra, uint32x2_t rb)
{
  return __rv_v_ukadd32 (ra, rb);
}
/* { dg-final { scan-assembler-times "ukadd32" 3 } } */
/* { dg-final { scan-assembler-times "builtin_riscv" 0 } } */
