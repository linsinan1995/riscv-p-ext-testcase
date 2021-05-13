/* This is a test program for umar64 instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpsf) && !defined(__riscv_32e)
static __attribute__ ((noinline))
uint64_t umar64 (uint64_t rd, unsigned long ra, unsigned long rb)
{
  return __rv__umar64 (rd, ra, rb);
}

int
main ()
{
  uint64_t a = umar64 (0x1, 0xffff0000ffff0000ll, 0x0001ffff0001ffffll);

  if (a != 0x3fffa00020001ll)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
