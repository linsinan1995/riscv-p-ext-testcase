/* This is a test program for ucmple16 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zpsf_zprv -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t elpmcu (uint32_t ra, uint32_t rb)
{
  return __rv__ucmple16 (ra, rb);
}

static __attribute__ ((noinline))
uint16x4_t elpmcu_v (uint16x4_t ra, uint16x4_t rb)
{
  return __rv__v_ucmple16 (ra, rb);
}
/* { dg-final { scan-assembler-times "ucmple16" 3 } } */
