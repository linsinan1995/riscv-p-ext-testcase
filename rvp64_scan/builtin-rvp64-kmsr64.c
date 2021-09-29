/* kmsr64 also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for kmsr64 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64i_zpn_zpsf -mabi=lp64 -O0" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int64_t rsmk (int64_t rd, int64_t ra, int64_t rb)
{
  return __rv_kmsr64 (rd, ra, rb);
}

static __attribute__ ((noinline))
int64_t rsmk2 (int64_t rd, int32x2_t ra, int32x2_t rb)
{
  return __rv_v_kmsr64 (rd, ra, rb);
}
/* { dg-final { scan-assembler-times "kmsr64" 3 } } */
/* { dg-final { scan-assembler-times "builtin_riscv" 0 } } */
