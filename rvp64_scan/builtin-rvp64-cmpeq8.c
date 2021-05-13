/* cmpeq8 also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for cmpeq8 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zprv_zpsf -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t qepmc (uint32_t ra, uint32_t rb)
{
  return __rv__cmpeq8 (ra, rb);
}

static __attribute__ ((noinline))
uint8x8_t qepmcs_v (int8x8_t ra, int8x8_t rb)
{
  return __rv__v_scmpeq8 (ra, rb);
}

static __attribute__ ((noinline))
uint8x8_t qepmcu_v (uint8x8_t ra, uint8x8_t rb)
{
  return __rv__v_ucmpeq8 (ra, rb);
}
/* { dg-final { scan-assembler-times "cmpeq8" 4 } } */
