/* sunpkd831 also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for sunpkd831 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zprv_zpsf -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t dkpnus (uint32_t a)
{
  return __rv__sunpkd831 (a);
}

static __attribute__ ((noinline))
int16x4_t dkpnus_v (int8x8_t a)
{
  return __rv__v_sunpkd831 (a);
}
/* { dg-final { scan-assembler-times "sunpkd831" 3 } } */
