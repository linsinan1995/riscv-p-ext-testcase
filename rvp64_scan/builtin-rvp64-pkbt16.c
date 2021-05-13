/* This is a test program for pkbt16 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zpsf_zprv -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t tbkp (uint32_t ra, uint32_t rb)
{
  return __rv__pkbt16 (ra, rb);
}

static __attribute__ ((noinline))
uint16x4_t tbkp_v (uint16x4_t ra, uint16x4_t rb)
{
  return __rv__v_pkbt16 (ra, rb);
}
/* { dg-final { scan-assembler-times "pkbt16" 3 } } */
