/* This is a test program for umulx16 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv32gc_zpn_zpsf -mabi=ilp32d -O2" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint64_t umulx16 (uint32_t ra, uint32_t rb)
{
  return __rv_umulx16 (ra, rb);
}

static __attribute__ ((noinline))
uint32x2_t v_umulx16 (uint16x2_t ra, uint16x2_t rb)
{
  return __rv_v_umulx16 (ra, rb);
}

int
main ()
{
  uint64_t a = umulx16 (0xffff0000, 0xffff0001);
  uint32x2_t va = v_umulx16 ((uint16x2_t) {0xffff, 0xffff},
			     (uint16x2_t) {1, 0});
  if (a != 0xffff00000000)
    abort ();
  else if (va[0] != 0
           || va[1] != 0xffff)
    abort ();
  else
    exit (0);
}
