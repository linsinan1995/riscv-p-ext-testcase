/* This is a test program for sub64 instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpsf) && !defined(__riscv_32e)
static __attribute__ ((noinline))
int64_t ssub64 (int64_t ra, int64_t rb)
{
  return __rv__ssub64 (ra, rb);
}

static __attribute__ ((noinline))
uint64_t usub64 (uint64_t ra, uint64_t rb)
{
  return __rv__usub64 (ra, rb);
}

int
main ()
{
  int64_t sa = ssub64 (0x100000000ll, 0xffffffffll);
  uint64_t ua = usub64 (0xf00000000ull, 0x1111ull);

  if (sa != 1ll)
    abort ();
  else if (ua != 0xeffffeeefull)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
