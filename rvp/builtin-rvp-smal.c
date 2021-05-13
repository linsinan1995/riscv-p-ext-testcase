/* This is a test program for smal instruction.  */
/* { dg-do run { target { riscv32*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpsf) && !defined(__riscv_32e)
static __attribute__ ((noinline))
int64_t smal (int64_t ra, unsigned long rb)
{
  return __rv__smal (ra, rb);
}

static __attribute__ ((noinline))
int64_t v_smal (int64_t ra, int16x2_t rb)
{
  return __rv__v_smal (ra, rb);
}

int
main ()
{
  int64_t a = smal (0xfffff0000ll, 0x0001ffff);
  int64_t va = v_smal (0xffffff0000ll,
			 (int16x2_t) {0x0002, 0xffff});
  if (a != 0xffffeffffll)
    abort ();
  else if (va != 0xfffffefffell)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
