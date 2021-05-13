/* This is a test program for ksll instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zpsf_zprv -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int llsk (int ra, uint32_t rb)
{
  return __rv__ksllw (ra, rb);
}
/* { dg-final { scan-assembler-times "ksllw" 1 } } */
