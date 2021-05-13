/* This is a test program for slli32 instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zprv) && !defined(__riscv_32e)
static __attribute__ ((noinline))
uint32_t slli32 (uint32_t ra)
{
  return __rv__sll32 (ra, 4);
}

static __attribute__ ((noinline))
uint32x2_t v_slli32 (uint32x2_t ra)
{
  return __rv__v_sll32 (ra, 4);
}

int
main ()
{
  uint32x2_t va_p = {0xfff80000, 0xfff80000};
  uint32_t a = slli32 (0x0ffff0000ffff000);
  uint32x2_t va = v_slli32 ((uint32x2_t) {0x7fff8000, 0x7fff8000});

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