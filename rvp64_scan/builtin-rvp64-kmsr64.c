/* kmsr64 also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for kmsr64 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zprv_zpsf -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int64_t rsmk (int64_t rd, long ra, long rb)
{
  return __rv__kmsr64 (rd, ra, rb);
}
/* { dg-final { scan-assembler-times "kmsr64" 2 } } */
