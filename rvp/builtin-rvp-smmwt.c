/* This is a test program for smmwt instruction.  */
/* { dg-do run { target { riscv32*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
int32_t smmwt (int32_t ra, uint32_t rb)
{
  return __rv__smmwt (ra, rb);
}

static __attribute__ ((noinline))
int32_t v_smmwt (int32_t ra, int16x2_t rb)
{
  return __rv__v_smmwt (ra, rb);
}

int
main ()
{
  int va_p = 0xffffffff;

  int32_t a = smmwt (0x80000002, 0x80000001);

  int32_t va = v_smmwt (0xffff0002, (int16x2_t) {0xffff, 0x0001});

  if (a != 0x3fffffff)
    abort ();
  else if (va != va_p)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
