/* rsubw also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for rsubw instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zprv_zpsf -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int32_t wbusr (int32_t ra, int32_t rb)
{
  return __rv__rsubw (ra, rb);
}
/* { dg-final { scan-assembler-times "rsubw" 2 } } */
