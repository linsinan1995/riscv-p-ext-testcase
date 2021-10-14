/* This is a test program for swap16 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>


static __attribute__ ((noinline))
uint64_t swap16 (uint64_t a)
{
  return __rv_swap16 (a);
}

static __attribute__ ((noinline))
uint16x4_t v_swap16 (uint16x4_t a)
{
  return __rv_v_swap16 (a);
}

int
main ()
{
  uint64_t a = 0x03020100;
  uint64_t b;

  b = swap16 (a);

  if (b != 0x02030001)
    abort ();
  else
    exit (0);
}
