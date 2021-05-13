/* This is a test program for zunpkd830 instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
uint32_t zunpkd830 (uint32_t a)
{
  return __rv__zunpkd830 (a);
}

static __attribute__ ((noinline))
uint16x4_t v_zunpkd830 (uint8x8_t a)
{
  return __rv__v_zunpkd830 (a);
}

int
main ()
{
  uint16x4_t va_p = {0x00f8, 0x0012, 0x00f8, 0x0012};
  uint32_t a = zunpkd830 (0x120000f8120000f8);
  uint16x4_t va = v_zunpkd830 ((uint8x8_t) {0xf8, 0x00, 0, 0x12, 0xf8, 0x00, 0, 0x12});

  if (a != 0x001200f8001200f8)
    abort ();
  else if (!vec64_all_eq (u, 16, va_p, va))
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif