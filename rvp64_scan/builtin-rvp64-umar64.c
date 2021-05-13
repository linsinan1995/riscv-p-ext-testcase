/* umar64 also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for umar64 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zprv_zpsf -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint64_t ramu (uint64_t rd, unsigned long ra, unsigned long rb)
{
  return __rv__umar64 (rd, ra, rb);
}
/* { dg-final { scan-assembler-times "umar64" 2 } } */
