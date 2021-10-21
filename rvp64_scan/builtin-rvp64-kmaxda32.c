/* kmaxda32 also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for kmaxda32 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O0" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int64_t adxamk (int64_t rd, uint64_t ra, uint64_t rb)
{
  return __rv_kmaxda32 (rd, ra, rb);
}

static __attribute__ ((noinline))
int64_t adxamk_v (int64_t rd, int32x2_t ra, int32x2_t rb)
{
  return __rv_v_kmaxda32 (rd, ra, rb);
}
/* { dg-final { scan-assembler-times "kmaxda32" 3 } } */
/* { dg-final { scan-assembler-times "builtin_riscv" 0 } } */
