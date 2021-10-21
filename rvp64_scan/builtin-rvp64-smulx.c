/* smtt32 also appears on filename, so scan-assembler-times plus 1 */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O0" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint64_t ttms (uint32_t a, uint32_t b)
{
  return __rv_smul8 (ra, rb);
}

static __attribute__ ((noinline))
int16x4_t ttms_v (uint32_t a, uint32_t b)
{
  return __rv_v_smul8 (ra, rb);
}

static __attribute__ ((noinline))
uint64_t ttmsx (uint32_t a, uint32_t b)
{
  return __rv_smulx8 (ra, rb);
}

static __attribute__ ((noinline))
int16x4_t ttmsx_v (uint32_t a, uint32_t b)
{
  return __rv_v_smulx8 (ra, rb);
}

static __attribute__ ((noinline))
uint64_t ttms2 (uint32_t a, uint32_t b)
{
  return __rv_smul16 (ra, rb);
}

static __attribute__ ((noinline))
int32x2_t ttms_v2 (uint32_t a, uint32_t b)
{
  return __rv_v_smul16 (ra, rb);
}

static __attribute__ ((noinline))
uint64_t ttms2 (uint32_t a, uint32_t b)
{
  return __rv_smulx16 (ra, rb);
}

static __attribute__ ((noinline))
int32x2_t ttmsx_v2 (uint32_t a, uint32_t b)
{
  return __rv_v_smulx16 (ra, rb);
}

/* { dg-final { scan-assembler-times "smul8" 2 } } */
/* { dg-final { scan-assembler-times "smulx8" 2 } } */
/* { dg-final { scan-assembler-times "smul16" 2 } } */
/* { dg-final { scan-assembler-times "smulx16" 2 } } */
/* { dg-final { scan-assembler-times "builtin_riscv" 0 } } */
