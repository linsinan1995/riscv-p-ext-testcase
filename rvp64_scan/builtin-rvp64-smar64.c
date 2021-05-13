/* This is a test program for smar64 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zpsf_zprv -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int64_t rams (int64_t rd, long ra, long rb)
{
  return __rv__smar64 (rd, ra, rb);
}
/* { dg-final { scan-assembler-times "smar64" 2 } } */
