/* This is a test program for ursub16 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv32gc_zpn -mabi=ilp32d -O2" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t ursub16 (uint32_t ra, uint32_t rb)
{
  return __rv_ursub16 (ra, rb);
}

static __attribute__ ((noinline))
uint16x2_t v_ursub16 (uint16x2_t ra, uint16x2_t rb)
{
  return __rv_v_ursub16 (ra, rb);
}

int
main ()
{
  uint32_t a = ursub16 (0x7fff7fff, 0x80008000);
  uint16x2_t va = v_ursub16 ((uint16x2_t) {0x8000, 0x8000},
			     (uint16x2_t) {0x7fff, 0x4000});

  if (a != 0xffffffff)
    abort ();
  else if (va[0] != 0
	   || va[1] != 0x2000)
    abort ();
  else
    exit (0);
}
