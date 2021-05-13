/* This is a test program for khmbt instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
int32_t khmbt (int ra, int rb)
{
  return __rv__khmbt (ra, rb);
}

static __attribute__ ((noinline))
int32_t v_khmbt (int16x4_t ra, int16x4_t rb)
{
  return __rv__v_khmbt (ra, rb);
}

int
main ()
{
  int32_t a = khmbt (0x0001f000, 0x00011000);
  int32_t v_sa = v_khmbt ((int16x4_t) {0xf777, 0xf111, 0, 0},
		       (int16x4_t) {0x1000, 0x2000, 0, 0});
  if (a != 0xffffffffffffffff)
    abort ();
  else if (v_sa != 0xfffffffffffffddd)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif