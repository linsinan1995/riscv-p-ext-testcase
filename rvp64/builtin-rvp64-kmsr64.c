/* This is a test program for kmsr64 instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpsf) && !defined(__riscv_32e)
static __attribute__ ((noinline))
int64_t kmsr64 (int64_t rd, long ra, long rb)
{
  return __rv__kmsr64 (rd, ra, rb);
}

int
main ()
{
  int64_t a = kmsr64 (0x1, 0xffff0000ffff0000ll, 0x0001ffff0001ffffll);

  if (a != 0x3fffe0001ll)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
