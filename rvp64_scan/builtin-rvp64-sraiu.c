/* This is a test program for srai.u instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64i_zpn_zprv_zpsf -mabi=lp64 -O0" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int64_t uiars (int64_t ra)
{
  return __rv__sra_u (ra, 8);
}
/* { dg-final { scan-assembler-times "srai.u" 1 } } */
/* { dg-final { scan-assembler-times "builtin_riscv" 0 } } */
