/* bitrev also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for bitrev instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zprv_zpsf -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t vertib (uint32_t ra, uint32_t rb)
{
  return __rv__bitrev (ra, rb);
}
/* { dg-final { scan-assembler-times "bitrev" 2 } } */
