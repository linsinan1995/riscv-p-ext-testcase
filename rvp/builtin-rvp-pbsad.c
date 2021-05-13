/* This is a test program for pbsad instruction.  */
/* { dg-do run { target { riscv32*-*-* } }} */
/* { dg-options "-O1" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
uint32_t pbsad (uint32_t ra, uint32_t rb)
{
  return __rv__pbsad (ra, rb);
}

int
main ()
{
  unsigned int a = 0x09070605;
  unsigned int b = 0x04020301;
  unsigned int r = __rv__pbsad (a, b);

  if (r != 17)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
