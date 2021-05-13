/* This is a test program for rsub64 instruction.  */
/* { dg-do run { target { riscv32*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpsf) && !defined(__riscv_32e)
static __attribute__ ((noinline))
int64_t rsub64 (int64_t ra, int64_t rb)
{
  return __rv__rsub64 (ra, rb);
}

int
main ()
{
  int64_t a = rsub64 (0xe, 0xf);

  if (a != 0xffffffffffffffff)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
