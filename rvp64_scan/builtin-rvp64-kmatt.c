/* kmatt also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for kmatt instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64i_zpn_zpsf -mabi=lp64 -O0" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int64_t ttamk (int64_t rd, uint64_t ra, uint64_t rb)
{
  return __rv_kmatt (rd, ra, rb);
}

static __attribute__ ((noinline))
int32x2_t ttamk_v (int32x2_t rd, int16x4_t ra, int16x4_t rb)
{
  return __rv_v_kmatt (rd, ra, rb);
}
/* { dg-final { scan-assembler-times "kmatt" 3 } } */
/* { dg-final { scan-assembler-times "builtin_riscv" 0 } } */
