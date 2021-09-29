/* This is a test program for scmplt16 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv32gc_zpn -mabi=ilp32d -O2" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t scmplt16 (uint32_t ra, uint32_t rb)
{
  return __rv_scmplt16 (ra, rb);
}

static __attribute__ ((noinline))
uint16x2_t v_scmplt16 (int16x2_t ra, int16x2_t rb)
{
  return __rv_v_scmplt16 (ra, rb);
}

int
main ()
{
  uint32_t a = scmplt16 (0xfffe0001, 0xffff0000);
  uint16x2_t va = v_scmplt16 ((int16x2_t) {0x7fff, 0x7ffe},
			      (int16x2_t) {0x7ffe, 0x7fff});

  if (a != 0xffff0000)
    abort ();
  else if (va[0] != 0
           || va[1] != 0xffff)
    abort ();
  else
    exit (0);
}
