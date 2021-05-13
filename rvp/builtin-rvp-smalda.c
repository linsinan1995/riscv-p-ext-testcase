/* This is a test program for smalda instruction.  */
/* { dg-do run { target { riscv32*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpsf) && !defined(__riscv_32e)
static __attribute__ ((noinline))
int64_t smalda (int64_t t, unsigned long a, unsigned long b)
{
  return __rv__smalda (t, a, b);
}

static __attribute__ ((noinline))
int64_t v_smalda (int64_t t, int16x2_t a, int16x2_t b)
{
  return __rv__v_smalda (t, a, b);
}


int
main ()
{
  int64_t a = smalda (0x12345678ffffffffll, 0x67890000, 0x12340000);
  int64_t va = v_smalda (0x12345678ffffffffll, (int16x2_t) {0, 0x6789},
						 (int16x2_t) {0, 0x1234});

  if (a != 0x12345679075CA9D3ll)
    abort ();
  else if (va != 0x12345679075CA9D3ll)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
