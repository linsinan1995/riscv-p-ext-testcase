/* This is a test program for urcras16 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv32gc_zpn -mabi=ilp32d -O2" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t urcras16 (uint32_t ra, uint32_t rb)
{
  return __rv_urcras16 (ra, rb);
}

static __attribute__ ((noinline))
uint16x2_t v_urcras16 (uint16x2_t ra, uint16x2_t rb)
{
  return __rv_v_urcras16 (ra, rb);
}

int
main ()
{
  uint16x2_t va_p = {0xffff, 0x8000};
  uint32_t a = urcras16 (0x7fff7fff, 0x80007fff);
  uint16x2_t va = v_urcras16 ((uint16x2_t) {0x7fff, 0x8000},
			      (uint16x2_t) {0x8000, 0x8000});

  if (a != 0x7fffffff)
    abort ();
  else if (va[0] != va_p[0]
	   || va[1] != va_p[1])
    abort ();
  else
    exit (0);
}
