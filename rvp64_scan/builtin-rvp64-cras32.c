/* cras32 also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for cras32 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64i_zpn_zprv_zpsf -mabi=lp64 -O0" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t sarc (uint32_t ra, uint32_t rb)
{
  return __rv__cras32 (ra, rb);
}

static __attribute__ ((noinline))
uint32x2_t sarcu_v (uint32x2_t ra, uint32x2_t rb)
{
  return __rv__v_ucras32 (ra, rb);
}

static __attribute__ ((noinline))
int32x2_t sarcs_v (int32x2_t ra, int32x2_t rb)
{
  return __rv__v_scras32 (ra, rb);
}
/* { dg-final { scan-assembler-times "cras32" 4 } } */
/* { dg-final { scan-assembler-times "builtin_riscv" 0 } } */
