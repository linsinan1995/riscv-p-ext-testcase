/* This is a test program for add64 instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpsf) && !defined(__riscv_32e)
static __attribute__ ((noinline))
int64_t sadd64 (int64_t ra, int64_t rb)
{
  return __rv__sadd64 (ra, rb);
}

static __attribute__ ((noinline))
uint64_t uadd64 (uint64_t ra, uint64_t rb)
{
  return __rv__uadd64 (ra, rb);
}

int
main ()
{
  int64_t sa = sadd64 (0x1122334400000000ll, 0x55667788ll);
  uint64_t ua = uadd64 (0xffff00000000ull, 0x55667788ull);

  if (sa != 0x1122334455667788ll)
    abort ();
  else if (ua != 0xffff55667788ull)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
