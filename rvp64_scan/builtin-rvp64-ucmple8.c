/* ucmple8 also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for ucmple8 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zprv_zpsf -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t elpmcu (uint32_t ra, uint32_t rb)
{
  return __rv__ucmple8 (ra, rb);
}

static __attribute__ ((noinline))
uint8x8_t elpmcu_v (uint8x8_t ra, uint8x8_t rb)
{
  return __rv__v_ucmple8 (ra, rb);
}
/* { dg-final { scan-assembler-times "ucmple8" 3 } } */
