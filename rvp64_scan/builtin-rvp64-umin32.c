/* This is a test program for umin32 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zpsf_zprv -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t nimu (uint32_t ra, uint32_t rb)
{
  return __rv__umin32 (ra, rb);
}

static __attribute__ ((noinline))
uint32x2_t nimu_v (uint32x2_t ra, uint32x2_t rb)
{
  return __rv__v_umin32 (ra, rb);
}
/* { dg-final { scan-assembler-times "umin32" 3 } } */
