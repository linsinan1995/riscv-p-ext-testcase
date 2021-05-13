/* This is a test program for sra16 instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
uint32_t sra16 (uint32_t ra, uint32_t rb)
{
  return __rv__sra16 (ra, rb);
}

static __attribute__ ((noinline))
int16x4_t v_sra16 (int16x4_t ra, uint32_t rb)
{
  return __rv__v_sra16 (ra, rb);
}

int
main ()
{
  uint32_t a = sra16 (0x0ffff0000ffff000, 4);
  int16x4_t va = v_sra16 ((int16x4_t) {0x7fff, 0x8000, 0x7fff, 0x8000}, 4);

  if (a != 0x00ffff0000ffff00)
    abort ();
  else if (va[0] != 0x7ff
	   || va[1] != (short) 0xf800
	   || va[2] != 0x7ff
	   || va[3] != (short) 0xf800)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
