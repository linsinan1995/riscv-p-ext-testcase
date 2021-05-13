/* This is a test program for smmwtu instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
int32_t smmwtu (int32_t ra, int32_t rb)
{
  return __rv__smmwt_u (ra, rb);
}

static __attribute__ ((noinline))
int32x2_t v_smmwtu (int32x2_t ra, int16x4_t rb)
{
  return __rv__v_smmwt_u (ra, rb);
}

int
main ()
{
  int32_t a = smmwtu (0x8000000080000000, 0x8000000180000001);
  int32x2_t va = v_smmwtu ((int32x2_t) {0x80000000, 0x80000000},
			   (int16x4_t) {0x1, 0x8000, 0x1, 0x8000});

  if (a != 0x4000000040000000)
    abort ();
  else if (va[0] != 0x40000000
	   || va[1] != 0x40000000)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif