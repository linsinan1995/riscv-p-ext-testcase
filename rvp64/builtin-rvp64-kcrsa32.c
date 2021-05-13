/* This is a test program for kcrsa32 instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zprv) && !defined(__riscv_32e)
static __attribute__ ((noinline))
uint32_t kcrsa32 (uint32_t ra, uint32_t rb)
{
  return __rv__kcrsa32 (ra, rb);
}

static __attribute__ ((noinline))
int32x2_t v_kcrsa32 (int32x2_t ra, int32x2_t rb)
{
  return __rv__v_kcrsa32 (ra, rb);
}

int
main ()
{
  int32x2_t sa_p = {0x7781111, 0xe777d111};
  uint32_t a = kcrsa32 (0x0001f0000001f000, 0x0001100000011000);
  int32x2_t v_sa = v_kcrsa32 ((int32x2_t) {0xf777f111, 0xf777f111},
			      (int32x2_t) {0x10002000, 0x10002000});

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
