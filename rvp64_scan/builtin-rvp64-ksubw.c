/* This is a test program for ksubw instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zpsf_zprv -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int wbusk (int ra, int rb)
{
  return __rv__ksubw (ra, rb);
}
/* { dg-final { scan-assembler-times "ksubw" 2 } } */
