/* This is a test program for ursub32 instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zprv) && !defined(__riscv_32e)
static __attribute__ ((noinline))
uint32_t ursub32 (uint32_t ra, uint32_t rb)
{
  return __rv__ursub32 (ra, rb);
}

static __attribute__ ((noinline))
uint32x2_t v_ursub32 (uint32x2_t ra, uint32x2_t rb)
{
  return __rv__v_ursub32 (ra, rb);
}

int
main ()
{
  uint32x2_t sa_p = {0x73bbe888, 0x73bbe888};
  uint32_t a = ursub32 (0x0001f0000001f000, 0x0001100000011000);
  uint32x2_t v_sa = v_ursub32 ((uint32x2_t) {0xf777f111, 0xf777f111},
			       (uint32x2_t) {0x10002000, 0x10002000});

  if (a != 0x700000007000)
    abort ();
  else if (sa_p[0] != v_sa[0]
	   || sa_p[1] != v_sa[1])
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
