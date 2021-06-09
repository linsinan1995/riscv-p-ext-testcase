/* This is a test program for srli16 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64i_zpn_zprv_zpsf -mabi=lp64 -O0" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint64_t ilrs (uint64_t ra)
{
  return __rv__srl16 (ra, 4);
}

static __attribute__ ((noinline))
uint16x4_t ilrs_v (uint16x4_t ra)
{
  return __rv__v_srl16 (ra, 4);
}
/* { dg-final { scan-assembler-times "srl16" 2 } } */
/* { dg-final { scan-assembler-times "builtin_riscv" 0 } } */
