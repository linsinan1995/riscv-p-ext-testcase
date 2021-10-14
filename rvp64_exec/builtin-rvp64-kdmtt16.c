/* This is a test program for kdmtt16 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>


static __attribute__ ((noinline))
uint64_t kdmtt16 (uint64_t ra, uint64_t rb)
{
  return __rv_kdmtt16 (ra, rb);
}

static __attribute__ ((noinline))
int32x2_t v_kdmtt16 (int16x4_t ra, int16x4_t rb)
{
  return __rv_v_kdmtt16 (ra, rb);
}

int
main ()
{
  int32_t a = kdmtt16 (0x0001f0000001f000, 0x0001100000011000);
  int32x2_t va = v_kdmtt16 ((int16x4_t) {0xf777, 0xf111, 0xf777, 0xf111},
			    (int16x4_t) {0x1000, 0x2000, 0x1000, 0x2000});
  if (a != 0x0000000200000002)
    abort ();
  else if (va[0] != 0xfc444000
	   || va[1] != 0xfc444000)
    abort ();
  else
    exit (0);
}
