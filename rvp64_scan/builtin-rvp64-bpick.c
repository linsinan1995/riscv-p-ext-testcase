/* bpick also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for bpick instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zprv_zpsf -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t kcipb (uint32_t ra, uint32_t rb, uint32_t rc)
{
  return __rv__bpick (ra, rb, rc);
}
/* { dg-final { scan-assembler-times "bpick" 2 } } */
