/* This is a test program for uradd64 instruction.  */
/* { dg-do run { target { riscv32*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpsf) && !defined(__riscv_32e)
static __attribute__ ((noinline))
uint64_t uradd64 (uint64_t ra, uint64_t rb)
{
  return __rv__uradd64 (ra, rb);
}

int
main ()
{
  uint64_t a = uradd64 (0xf000000000000000ull, 0xf000000000000000ull);

  if (a != 0xf000000000000000ull)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
