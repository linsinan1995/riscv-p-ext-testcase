/* This is a test program for sunpkd820 instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
uint32_t sunpkd820 (uint32_t a)
{
  return __rv__sunpkd820 (a);
}

static __attribute__ ((noinline))
int16x4_t v_sunpkd820 (int8x8_t a)
{
  return __rv__v_sunpkd820 (a);
}

int
main ()
{
  int16x4_t va_p = {0xfff8, 0x34, 0xfff8, 0x34};
  uint32_t a = sunpkd820 (0x003400f8003400f8);
  int16x4_t va = v_sunpkd820 ((int8x8_t) {0xf8, 0, 0x34, 0, 0xf8, 0, 0x34, 0});

  if (a != 0x0034fff80034fff8)
    abort ();
  else if (!vec64_all_eq (s, 16, va_p, va))
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif