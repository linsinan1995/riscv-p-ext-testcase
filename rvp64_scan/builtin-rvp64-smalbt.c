/* This is a test program for smalbt instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zpsf_zprv -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int64_t tblams (int64_t t, unsigned long a, unsigned long b)
{
  return __rv__smalbt (t, a, b);
}

static __attribute__ ((noinline))
int64_t tblams_v (int64_t t, int16x4_t a, int16x4_t b)
{
  return __rv__v_smalbt (t, a, b);
}

/* { dg-final { scan-assembler-times "smalbt" 3 } } */
