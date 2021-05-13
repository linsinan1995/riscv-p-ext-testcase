/* This is a test program for pbsada instruction.  */
/* { dg-do run { target { riscv32*-*-* } } } */
/* { dg-options "-O1" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
uint32_t pbsada (uint32_t ra, uint32_t rb, uint32_t rc)
{
  return __rv__pbsada (ra, rb, rc);
}

int
main ()
{
  uint32_t a = 0x09070605;
  uint32_t b = 0x04020301;
  uint32_t r = 1;

  r = pbsada(r, a, b);

  if (r != 18)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
