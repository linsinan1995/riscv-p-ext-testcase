/* kmaxda also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for kmaxda instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zprv_zpsf -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int32_t adxamk (uint32_t rd, uint32_t ra, uint32_t rb)
{
  return __rv__kmaxda (rd, ra, rb);
}

static __attribute__ ((noinline))
int32x2_t adxamk_v (int32x2_t rd, int16x4_t ra, int16x4_t rb)
{
  return __rv__v_kmaxda (rd, ra, rb);
}
/* { dg-final { scan-assembler-times "kmaxda" 3 } } */