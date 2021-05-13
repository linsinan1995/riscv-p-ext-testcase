/* This is a test program for ukcrsa32 instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zprv) && !defined(__riscv_32e)
static __attribute__ ((noinline))
uint32_t ukcrsa32 (uint32_t ra, uint32_t rb)
{
  return __rv__ukcrsa32 (ra, rb);
}

static __attribute__ ((noinline))
uint32x2_t v_ukcrsa32 (uint32x2_t ra, uint32x2_t rb)
{
  return __rv__v_ukcrsa32 (ra, rb);
}

int
main ()
{
  uint32x2_t sa_p = {0xffffffff, 0xe777d111};
  uint32_t a = ukcrsa32 (0x0001f0000001f000, 0x0001100000011000);
  uint32x2_t v_sa = v_ukcrsa32 ((uint32x2_t) {0xf777f111, 0xf777f111},
				(uint32x2_t) {0x10002000, 0x10002000});

  if (a != 0x0000e00000030000)
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
