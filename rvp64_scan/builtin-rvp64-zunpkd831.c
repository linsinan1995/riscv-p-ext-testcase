/* This is a test program for zunpkd831 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zpsf_zprv -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t dkpnuz (uint32_t a)
{
  return __rv__zunpkd831 (a);
}

static __attribute__ ((noinline))
uint16x4_t dkpnuz_v (uint8x8_t a)
{
  return __rv__v_zunpkd831 (a);
}
/* { dg-final { scan-assembler-times "zunpkd831" 3 } } */
