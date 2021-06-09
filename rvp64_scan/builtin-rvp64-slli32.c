/* This is a test program for slli32 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64i_zpn_zprv_zpsf -mabi=lp64 -O0" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint64_t ills (uint64_t ra)
{
  return __rv__sll32 (ra, 4);
}

static __attribute__ ((noinline))
uint32x2_t ills_v (uint32x2_t ra)
{
  return __rv__v_sll32 (ra, 4);
}
/* { dg-final { scan-assembler-times "sll32" 2 } } */
/* { dg-final { scan-assembler-times "builtin_riscv" 0 } } */
