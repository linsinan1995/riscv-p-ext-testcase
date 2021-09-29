/* This is a test program for smax16 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv32gc_zpn -mabi=ilp32d -O2" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t smax16 (uint32_t ra, uint32_t rb)
{
  return __rv_smax16 (ra, rb);
}

static __attribute__ ((noinline))
int16x2_t v_smax16 (int16x2_t ra, int16x2_t rb)
{
  return __rv_v_smax16 (ra, rb);
}

int
main ()
{
  uint32_t a = smax16 (0xfffe0001, 0xffff0000);
  int16x2_t va = v_smax16 ((int16x2_t) {0x7fff, 0},
			   (int16x2_t) {0x7ffe, 1});
  if (a != 0xffff0001)
    abort ();
  else if (va[0] != 0x7fff
           || va[1] != 1)
    abort ();
  else
    exit (0);
}
