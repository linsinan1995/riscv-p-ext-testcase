/* This is a test program for smalbb instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpsf) && !defined(__riscv_32e)
static __attribute__ ((noinline))
int64_t smalbb (int64_t t, unsigned long a, unsigned long b)
{
  return __rv__smalbb (t, a, b);
}

static __attribute__ ((noinline))
int64_t v_smalbb (int64_t t, int16x4_t a, int16x4_t b)
{
  return __rv__v_smalbb (t, a, b);
}


int
main ()
{
  int64_t a = smalbb (0x12345678ffffffffll, 0x6789000067890000, 0x1234000012340000);
  int64_t va = v_smalbb (0x12345678ffffffffll, (int16x4_t) {0, 0x6789, 0, 0x6789},
						 (int16x4_t) {0, 0x1234, 0, 0x1234});

  if (a != 0x12345678ffffffffll)
    abort ();
  else if (va != 0x12345678ffffffffll)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
