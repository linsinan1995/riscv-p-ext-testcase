/* This is a test program for kmar64 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zpsf_zprv -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int64_t ramk (int64_t rd, long ra, long rb)
{
  return __rv__kmar64 (rd, ra, rb);
}
/* { dg-final { scan-assembler-times "kmar64" 2 } } */
