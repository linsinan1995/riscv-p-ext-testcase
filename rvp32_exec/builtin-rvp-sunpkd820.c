/* This is a test program for sunpkd820 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv32gc_zpn -mabi=ilp32d -O2" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t sunpkd820 (uint32_t a)
{
  return __rv_sunpkd820 (a);
}

static __attribute__ ((noinline))
int16x2_t v_sunpkd820 (int8x4_t a)
{
  return __rv_v_sunpkd820 (a);
}

int
main ()
{
  int16x2_t va_p = {0xfff8, 0x34};
  uint32_t a = sunpkd820 (0x003400f8);
  int16x2_t va = v_sunpkd820 ((int8x4_t) {0xf8, 0, 0x34, 0});

  if (a != 0x0034fff8)
    abort ();
  else if (va[0] != va_p[0]
           || va[1] != va_p[1])
    abort ();
  else
    exit (0);
}
