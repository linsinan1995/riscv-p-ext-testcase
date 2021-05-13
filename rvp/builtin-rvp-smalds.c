/* This is a test program for smalds instruction.  */
/* { dg-do run { target { riscv32*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpsf) && !defined(__riscv_32e)
static __attribute__ ((noinline))
int64_t smalds (int64_t t, unsigned long a, unsigned long b)
{
  return __rv__smalds (t, a, b);
}

static __attribute__ ((noinline))
int64_t v_smalds (int64_t t, int16x2_t a, int16x2_t b)
{
  return __rv__v_smalds (t, a, b);
}


int
main ()
{
  int64_t a_p = 0x12345678ffffaaaall;
  int64_t va_p = 0x12345678ffffaaaall;
  int64_t a = smalds (0x12345678ffffffffll, 0x12340001, 0x00016789);
  int64_t va = v_smalds (0x12345678ffffffffll, (int16x2_t) {0x0001, 0x1234},
						 (int16x2_t) {0x6789, 0x0001});

  if (a != a_p)
    abort ();
  else if (va != va_p)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
