/* This is a test program for kslli instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zprv_zpsf -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int illsk (int ra)
{
  return __rv__ksllw (ra, 8);
}
/* { dg-final { scan-assembler-times "ksllw" 1 } } */