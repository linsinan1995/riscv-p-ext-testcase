/* This is a test program for ksub64 instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpsf) && !defined(__riscv_32e)
static __attribute__ ((noinline))
int64_t ksub64 (int64_t ra, int64_t rb)
{
  return __rv__ksub64 (ra, rb);
}

int
main ()
{
  int64_t sa = ksub64 (0x1122334400000000ll, 0x55667788ll);

  if (sa != 0x11223343aa998878)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif