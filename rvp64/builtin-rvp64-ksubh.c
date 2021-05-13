/* This is a test program for ksubh instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
int ksubh (int ra, int rb)
{
  return __rv__ksubh (ra, rb);
}

int
main ()
{
  int sa = ksubh (0x11223344, 0x55667788);

  if (sa != 0xffffffffffff8000)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
