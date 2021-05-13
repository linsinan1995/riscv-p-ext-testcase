/* This is a test program for kadd64 instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpsf) && !defined(__riscv_32e)
static __attribute__ ((noinline))
int64_t kadd64 (int64_t ra, int64_t rb)
{
  return __rv__kadd64 (ra, rb);
}

int
main ()
{
  int64_t sa = kadd64 (0x1122334400000000ll, 0x55667788ll);

  if (sa != 0x1122334455667788ll)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
