/* This is a test program for umax16 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv32gc_zpn -mabi=ilp32d -O2" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t umax16 (uint32_t ra, uint32_t rb)
{
  return __rv_umax16 (ra, rb);
}

static __attribute__ ((noinline))
uint16x2_t v_umax16 (uint16x2_t ra, uint16x2_t rb)
{
  return __rv_v_umax16 (ra, rb);
}

int
main ()
{
  uint32_t a = umax16 (0xfffe0001, 0xffff0000);
  uint16x2_t va = v_umax16 ((uint16x2_t) {0xffff, 0},
			    (uint16x2_t) {0xfffe, 1});
  if (a != 0xffff0001)
    abort ();
  else if (va[0] != 0xffff
           || va[1] != 1)
    abort ();
  else
    exit (0);
}
