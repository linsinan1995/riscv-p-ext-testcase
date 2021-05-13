/* smtt32 also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for smtt32 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zprv_zpsf -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int32_t ttms (uint32_t ra, uint32_t rb)
{
  return __rv__smtt32 (ra, rb);
}

static __attribute__ ((noinline))
int32_t ttms_v (int32x2_t ra, int32x2_t rb)
{
  return __rv__v_smtt32 (ra, rb);
}
/* { dg-final { scan-assembler-times "smtt32" 3 } } */
