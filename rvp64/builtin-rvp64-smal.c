/* This is a test program for smal instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpsf) && !defined(__riscv_32e)
static __attribute__ ((noinline))
int64_t smal (int64_t ra, int64_t rb)
{
  return __rv__smal (ra, rb);
}

static __attribute__ ((noinline))
int64_t v_smal (int64_t ra, int16x4_t rb)
{
  return __rv__v_smal (ra, rb);
}

int
main ()
{
  int64_t a = smal (0xffff0000ffff0000ll, 0x0001ffff0001ffffll);
  int64_t va = v_smal (0xffffff00ffffff00ll,
			 (int16x4_t) {0x0002, 0xffff, 0x0002, 0xffff});
  if (a != 0xffff0000fffefffe)
    abort ();
  else if (va != 0xffffff00fffffefc)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
