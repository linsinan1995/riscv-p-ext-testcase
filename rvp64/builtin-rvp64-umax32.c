/* This is a test program for umax32 instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zprv) && !defined(__riscv_32e)
static __attribute__ ((noinline))
uint32_t umax32 (uint32_t ra, uint32_t rb)
{
  return __rv__umax32 (ra, rb);
}

static __attribute__ ((noinline))
uint32x2_t v_umax32 (uint32x2_t ra, uint32x2_t rb)
{
  return __rv__v_umax32 (ra, rb);
}

int
main ()
{
  uint32x2_t va_p = {0x7fff0000, 0x7fff0000};
  uint32_t a = umax32 (0xfffe0001fffe0001, 0xffff0000ffff0000);
  uint32x2_t va = v_umax32 ((uint32x2_t) {0x7fff0000, 0x7fff0000},
			    (uint32x2_t) {0x7ffe1000, 0x7ffe1000});
  if (a != 0xffff0000ffff0000)
    abort ();
  else if (va[0] != va_p[0]
	   || va[1] != va_p[1])
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
