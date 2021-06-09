/* kdmtt also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for kdmtt instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64i_zpn_zprv_zpsf -mabi=lp64 -O0" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int32_t ttmdk (int ra, int rb)
{
  return __rv__kdmtt (ra, rb);
}

static __attribute__ ((noinline))
int32_t ttmdk_v (int16x2_t ra, int16x2_t rb)
{
  return __rv__v_kdmtt (ra, rb);
}
/* { dg-final { scan-assembler-times "kdmtt" 3 } } */
/* { dg-final { scan-assembler-times "builtin_riscv" 0 } } */
