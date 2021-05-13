/* This is a test program for umsr64 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zpsf_zprv -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint64_t rsmu (uint64_t rd, unsigned long ra, unsigned long rb)
{
  return __rv__umsr64 (rd, ra, rb);
}
/* { dg-final { scan-assembler-times "umsr64" 2 } } */
