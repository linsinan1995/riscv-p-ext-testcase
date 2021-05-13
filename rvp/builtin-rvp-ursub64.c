/* This is a test program for ursub64 instruction.  */
/* { dg-do run { target { riscv32*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpsf) && !defined(__riscv_32e)
static __attribute__ ((noinline))
uint64_t ursub64 (uint64_t ra, uint64_t rb)
{
  return __rv__ursub64 (ra, rb);
}

int
main ()
{
  uint64_t a = ursub64 (0xeull, 0xfull);

  if (a != 0xffffffffffffffffull)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
