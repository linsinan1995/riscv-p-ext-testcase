/* This is a test program for sunpkd831 instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
uint32_t sunpkd831 (uint32_t a)
{
  return __rv__sunpkd831 (a);
}

static __attribute__ ((noinline))
int16x4_t v_sunpkd831 (int8x8_t a)
{
  return __rv__v_sunpkd831 (a);
}

int
main ()
{
  int16x4_t va_p = {0xfff8, 0x12, 0xfff8, 0x12};
  uint32_t a = sunpkd831 (0x1200f8001200f800);
  int16x4_t va = v_sunpkd831 ((int8x8_t) {0, 0xf8, 0, 0x12, 0, 0xf8, 0, 0x12});

  if (a != 0x0012fff80012fff8)
    abort ();
  else if (!vec64_all_eq (s, 16, va_p, va))
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif