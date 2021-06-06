/* This is a test program for kmmacu instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64i_zpn_zprv_zpsf -mabi=lp64 -O0" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int32_t ucammk (int32_t rd, int32_t ra, int32_t rb)
{
  return __rv__kmmac_u (rd, ra, rb);
}
/* { dg-final { scan-assembler-times "kmmac.u" 1 } } */
/* { dg-final { scan-assembler-times "builtin_riscv" 0 } } */
