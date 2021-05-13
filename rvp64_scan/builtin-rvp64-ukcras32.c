/* ukcras32 also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for ukcras32 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zprv_zpsf -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t sarcku (uint32_t ra, uint32_t rb)
{
  return __rv__ukcras32 (ra, rb);
}

static __attribute__ ((noinline))
uint32x2_t sarcku_v (uint32x2_t ra, uint32x2_t rb)
{
  return __rv__v_ukcras32 (ra, rb);
}
/* { dg-final { scan-assembler-times "ukcras32" 3 } } */
