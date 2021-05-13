/* This is a test program for smslda instruction.  */
/* { dg-do run { target { riscv32*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
int64_t smslda (int64_t rt, unsigned long ra, unsigned long rb)
{
  return __rv__smslda (rt, ra, rb);
}

static __attribute__ ((noinline))
int64_t v_smslda (int64_t rt, int16x2_t ra, int16x2_t rb)
{
  return __rv__v_smslda (rt, ra, rb);
}

int
main ()
{
  int64_t a = smslda (0xff0000000000ll, 0xffffffff, 0x2);
  int64_t va = v_smslda (0x100000000ll,
			   (int16x2_t) {0xf000, 0}, (int16x2_t) {0, 3});

  if (a != 0xff0000000002ll)
    abort ();
  else if (va != 0x100000000ll)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
