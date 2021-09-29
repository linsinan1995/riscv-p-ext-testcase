/* This is a test program for radd8 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv32gc_zpn -mabi=ilp32d -O2" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t radd8 (uint32_t ra, uint32_t rb)
{
  return __rv_radd8 (ra, rb);
}

static __attribute__ ((noinline))
int8x4_t v_radd8 (int8x4_t ra, int8x4_t rb)
{
  return __rv_v_radd8 (ra, rb);
}

int
main ()
{
  uint32_t a = radd8 (0x11223344, 0x55667788);
  int8x4_t va = v_radd8 ((int8x4_t) {0x7f, 0x80, 0x80, 0xaa},
			 (int8x4_t) {0x7f, 0x80, 0x40, 0xaa});

  if (a != 0x334455e6)
    abort ();
  else if (va[0] != 0x7f
	   || va[1] != (signed char) 0x80
	   || va[2] != (signed char) 0xe0
	   || va[3] != (signed char) 0xaa)
    abort ();
  else
    exit (0);
}
