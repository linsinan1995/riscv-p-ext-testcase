/* This is a test program for scmple16 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv32gc_zpn -mabi=ilp32d -O2" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t scmple16 (uint32_t ra, uint32_t rb)
{
  return __rv_scmple16 (ra, rb);
}

static __attribute__ ((noinline))
uint16x2_t v_scmple16 (int16x2_t ra, int16x2_t rb)
{
  return __rv_v_scmple16 (ra, rb);
}

int
main ()
{
  uint32_t a = scmple16 (0xfffe0001, 0xffff0000);
  uint16x2_t va = v_scmple16 ((int16x2_t) {0x7fff, 0x7ffe},
			      (int16x2_t) {0x7ffe, 0x7fff});
  if (a != 0xffff0000)
    abort ();
  else if (va[0] != 0
           || va[1] != 0xffff)
    abort ();
  else
    exit (0);
}
