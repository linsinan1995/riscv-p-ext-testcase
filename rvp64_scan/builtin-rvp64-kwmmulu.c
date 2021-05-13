/* This is a test program for kwmmulu instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zpsf_zprv -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int32_t ulummwk (int32_t ra, int32_t rb)
{
  return __rv__kwmmul_u (ra, rb);
}
/* { dg-final { scan-assembler-times "kwmmul_u" 1 } } */
