/* This is a test program for sunpkd820 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zprv_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
uint64_t sunpkd820 (uint64_t a)
{
  return __rv_sunpkd820 (a);
}

static __attribute__ ((noinline))
int16x4_t v_sunpkd820 (int8x8_t a)
{
  return __rv_v_sunpkd820 (a);
}

int
main ()
{
  int16x4_t va_p = {0xfff8, 0x34, 0xfff8, 0x34};
  uint64_t a = sunpkd820 (0x003400f8003400f8);
  int16x4_t va = v_sunpkd820 ((int8x8_t) {0xf8, 0, 0x34, 0, 0xf8, 0, 0x34, 0});

  if (a != 0x0034fff80034fff8)
    abort ();
  else if (!vec64_all_eq (s, 16, va_p, va))
    abort ();
  else
    exit (0);
}
