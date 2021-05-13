/* This is a test program for umul8 instruction.  */
/* { dg-do run { target { riscv32*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpsf) && !defined(__riscv_32e)
static __attribute__ ((noinline))
uint64_t umul8 (unsigned long ra, unsigned long rb)
{
  return __rv__umul8 (ra, rb);
}

static __attribute__ ((noinline))
uint16x4_t v_umul8 (uint8x4_t ra, uint8x4_t rb)
{
  return __rv__v_umul8 (ra, rb);
}

int
main ()
{
  uint64_t a = umul8 (0xffff0000, 0x0001ffff);
  uint16x4_t va = v_umul8 ((uint8x4_t) {0xff, 0xee, 0xdd, 0xcc},
			    (uint8x4_t) {0x11, 0x22, 0x33, 0x44});

  if (a != 0xff00000000)
    abort ();
  else if (va[0] != 0x10ef
           || va[1] != 0x1f9c
           || va[2] != 0x2c07
           || va[3] != 0x3630)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
