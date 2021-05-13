/* This is a test program for slli32 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zpsf_zprv -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t ills (uint32_t ra)
{
  return __rv__sll32 (ra, 4);
}

static __attribute__ ((noinline))
uint32x2_t ills_v (uint32x2_t ra)
{
  return __rv__v_sll32 (ra, 4);
}
/* { dg-final { scan-assembler-times "sll32" 2 } } */
