/* kmsda32 also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for kmsda32 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64i_zpn_zpsf -mabi=lp64 -O0" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int64_t adsmk (int64_t rd, uint64_t ra, uint64_t rb)
{
  return __rv_kmsda32 (rd, ra, rb);
}

static __attribute__ ((noinline))
int64_t adsmk_v (int64_t rd, int32x2_t ra, int32x2_t rb)
{
  return __rv_v_kmsda32 (rd, ra, rb);
}
/* { dg-final { scan-assembler-times "kmsda32" 3 } } */
/* { dg-final { scan-assembler-times "builtin_riscv" 0 } } */
