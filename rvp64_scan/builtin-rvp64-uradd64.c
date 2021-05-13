/* radd64 also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for radd64 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zprv_zpsf -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int64_t ddar (int64_t ra, int64_t rb)
{
  return __rv__radd64 (ra, rb);
}
/* { dg-final { scan-assembler-times "radd64" 2 } } */
