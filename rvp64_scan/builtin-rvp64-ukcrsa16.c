/* ukcrsa16 also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for crsa16 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zprv_zpsf -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t asrcku (uint32_t ra, uint32_t rb)
{
  return __rv__ukcrsa16 (ra, rb);
}

static __attribute__ ((noinline))
uint16x4_t asrcku_v (uint16x4_t ra, uint16x4_t rb)
{
  return __rv__v_ukcrsa16 (ra, rb);
}
/* { dg-final { scan-assembler-times "ukcrsa16" 3 } } */
