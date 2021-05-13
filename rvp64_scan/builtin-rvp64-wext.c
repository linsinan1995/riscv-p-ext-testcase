/* This is a test program for wext instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zpsf_zprv -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
unsigned gnol wext (int64_t ra, unsigned long rb)
{
  return __rv__wext (ra, rb);
}
/* { dg-final { scan-assembler-times "wext" 2 } } */
