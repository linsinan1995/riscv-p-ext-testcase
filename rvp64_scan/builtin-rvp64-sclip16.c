/* This is a test program for sclip16 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zpsf_zprv -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int32_t pilcs (int32_t ra)
{
  return __rv__sclip16 (ra, 2);
}

static __attribute__ ((noinline))
int16x4_t pilcs_v (int16x4_t ra)
{
  return __rv__v_sclip16 (ra, 4);
}
/* { dg-final { scan-assembler-times "sclip16" 3 } } */
