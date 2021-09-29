/* This is a test program for smin16 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv32gc_zpn -mabi=ilp32d -O2" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t smin16 (uint32_t ra, uint32_t rb)
{
  return __rv_smin16 (ra, rb);
}

static __attribute__ ((noinline))
int16x2_t v_smin16 (int16x2_t ra, int16x2_t rb)
{
  return __rv_v_smin16 (ra, rb);
}

int
main ()
{
  uint32_t a = smin16 (0xfffe0001, 0xffff0000);
  int16x2_t v_sa = v_smin16 ((int16x2_t) {0x7fff, 0},
			     (int16x2_t) {0x7ffe, 1});
  if (a != 0xfffe0000)
    abort ();
  else if (v_sa[0] != 0x7ffe
           || v_sa[1] != 0)
    abort ();
  else
    exit (0);
}
