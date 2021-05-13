/* kabs16 also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for kabs16 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zprv_zpsf -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t sbak (uint32_t ra)
{
  return __rv__kabs16 (ra);
}

static __attribute__ ((noinline))
int16x4_t sbak_v (int16x4_t ra)
{
  return __rv__v_kabs16 (ra);
}
/* { dg-final { scan-assembler-times "kabs16" 3 } } */
