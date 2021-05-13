/* This is a test program for rcrsa16 instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
uint32_t rcrsa16 (uint32_t ra, uint32_t rb)
{
  return __rv__rcrsa16 (ra, rb);
}

static __attribute__ ((noinline))
int16x4_t v_rcrsa16 (int16x4_t ra, int16x4_t rb)
{
  return __rv__v_rcrsa16 (ra, rb);
}

int
main ()
{
  int16x4_t va_p = {0x8000, 0x8000, 0x8000, 0x8000};
  uint32_t a = rcrsa16 (0x7fff7fff7fff7fff, 0x7fff80007fff8000);
  int16x4_t va = v_rcrsa16 ((int16x4_t) {0x8000, 0x8000, 0x8000, 0x8000},
			    (int16x4_t) {0x7fff, 0x8000, 0x7fff, 0x8000});

  if (a != 0x7fff7fff7fff7fff)
    abort ();
  else if (va[0] != va_p [0]
	   || va[1] != va_p [1]
	   || va[2] != va_p [2]
	   || va[3] != va_p [3])
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
