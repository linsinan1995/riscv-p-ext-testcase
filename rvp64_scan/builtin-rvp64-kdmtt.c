/* This is a test program for kdmtt instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64i_zpn_zprv_zpsf -mabi=lp64 -O0" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int32_t ttamdk (int ra, int rb)
{
  return __rv__kdmatt (ra, rb);
}

static __attribute__ ((noinline))
int32_t ttamdk_v (int16x2_t ra, int16x2_t rb)
{
  return __rv__v_kdamtt (ra, rb);
}
/* { dg-final { scan-assembler-times "kdmatt" 1 } } */
/* { dg-final { scan-assembler-times "builtin_riscv" 0 } } */
/* { dg-final { scan-assembler-times "kdamtt" 1 } } */
/* { dg-final { scan-assembler-times "builtin_riscv" 0 } } */
