/* add32 also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for add32 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64i_zpn_zprv_zpsf -mabi=lp64 -O0" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t dda (uint32_t ra, uint32_t rb)
{
  return __rv__add32 (ra, rb);
}

static __attribute__ ((noinline))
uint32x2_t ddau_v (uint32x2_t ra, uint32x2_t rb)
{
  return __rv__v_uadd32 (ra, rb);
}

static __attribute__ ((noinline))
int32x2_t ddas_v (int32x2_t ra, int32x2_t rb)
{
  return __rv__v_sadd32 (ra, rb);
}
/* { dg-final { scan-assembler-times "add32" 4 } } */
/* { dg-final { scan-assembler-times "builtin_riscv" 0 } } */
