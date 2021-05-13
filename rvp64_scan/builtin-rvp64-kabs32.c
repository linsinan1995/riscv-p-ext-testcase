/* kabs32 also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for kabs32 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zprv_zpsf -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t sbak (uint32_t ra)
{
  return __rv__kabs32 (ra);
}

static __attribute__ ((noinline))
int32x2_t sbak_v (int32x2_t ra)
{
  return __rv__v_kabs32 (ra);
}
/* { dg-final { scan-assembler-times "kabs32" 3 } } */
