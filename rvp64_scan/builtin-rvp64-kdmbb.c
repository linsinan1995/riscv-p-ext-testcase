/* kdmbb also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for kdmbb instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zprv_zpsf -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int32_t bbmdk (int ra, int rb)
{
  return __rv__kdmbb (ra, rb);
}

static __attribute__ ((noinline))
int32_t bbmdk_v (int16x4_t ra, int16x4_t rb)
{
  return __rv__v_kdmbb (ra, rb);
}
/* { dg-final { scan-assembler-times "kdmbb" 3 } } */