/* This is a test program for ave instruction.  */
/* { dg-do run { target { riscv32*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
int32_t ave (int32_t ra, int32_t rb)
{
  return __rv__ave (ra, rb);
}


int
main ()
{
  int a = 4;
  int b = 2;
  int ave = ave (a, b);

  if (ave != 3)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
