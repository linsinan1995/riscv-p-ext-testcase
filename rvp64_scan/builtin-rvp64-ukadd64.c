/* This is a test program for ukadd64 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zpsf_zprv -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint64_t ddaku (uint64_t ra, uint64_t rb)
{
  return __rv__ukadd64 (ra, rb);
}
/* { dg-final { scan-assembler-times "ukadd64" 2 } } */
