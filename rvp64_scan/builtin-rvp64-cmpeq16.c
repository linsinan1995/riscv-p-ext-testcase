/* cmpeq16 also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for cmpeq16 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zprv_zpsf -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint64_t qepmc (uint64_t ra, uint64_t rb)
{
  return __rv__cmpeq16 (ra, rb);
}
static __attribute__ ((noinline))
uint16x4_t qepmcs_v (int16x4_t ra, int16x4_t rb)
{
  return __rv__v_scmpeq16 (ra, rb);
}
static __attribute__ ((noinline))
uint16x4_t qepmcu_v (uint16x4_t ra, uint16x4_t rb)
{
  return __rv__v_ucmpeq16 (ra, rb);
}
/* { dg-final { scan-assembler-times "cmpeq16" 4 } } */
