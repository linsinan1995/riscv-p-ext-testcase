/* This is a test program for uradd16 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv32gc_zpn -mabi=ilp32d -O2" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t uradd16 (uint32_t ra, uint32_t rb)
{
  return __rv_uradd16 (ra, rb);
}

static __attribute__ ((noinline))
uint16x2_t v_uradd16 (uint16x2_t ra, uint16x2_t rb)
{
  return __rv_v_uradd16 (ra, rb);
}

int
main ()
{
  uint32_t a = uradd16 (0x7fff7fff, 0x7fff7fff);
  uint16x2_t va = v_uradd16 ((uint16x2_t) {0x8000, 0x4000},
			     (uint16x2_t) {0x8000, 0x8000});

  if (a != 0x7fff7fff)
    abort ();
  else if (va[0] != 0x8000
	   || va[1] != 0x6000)
    abort ();
  else
    exit (0);
}
