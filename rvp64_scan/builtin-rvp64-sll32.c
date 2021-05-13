/* sll32 also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for sll32 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zprv_zpsf -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t lls (uint32_t ra, uint32_t rb)
{
  return __rv__sll32 (ra, rb);
}

static __attribute__ ((noinline))
uint32x2_t lls_v (uint32x2_t ra, uint32_t rb)
{
  return __rv__v_sll32 (ra, rb);
}
/* { dg-final { scan-assembler-times "sll32" 3 } } */
