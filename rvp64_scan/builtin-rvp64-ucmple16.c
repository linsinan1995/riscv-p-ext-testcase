/* ucmple16 also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for ucmple16 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64i_zpn_zprv_zpsf -mabi=lp64 -O0" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint64_t elpmcu (uint64_t ra, uint64_t rb)
{
  return __rv__ucmple16 (ra, rb);
}

static __attribute__ ((noinline))
uint16x4_t elpmcu_v (uint16x4_t ra, uint16x4_t rb)
{
  return __rv__v_ucmple16 (ra, rb);
}
/* { dg-final { scan-assembler-times "ucmple16" 3 } } */
/* { dg-final { scan-assembler-times "builtin_riscv" 0 } } */
