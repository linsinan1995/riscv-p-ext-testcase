/* This is a test program for kmatt instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zpsf_zprv -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int32_t ttamk (uint32_t rd, uint32_t ra, uint32_t rb)
{
  return __rv__kmatt (rd, ra, rb);
}

static __attribute__ ((noinline))
int32x2_t ttamk_v (int32x2_t rd, int16x4_t ra, int16x4_t rb)
{
  return __rv__v_kmatt (rd, ra, rb);
}
/* { dg-final { scan-assembler-times "kmatt" 3 } } */
