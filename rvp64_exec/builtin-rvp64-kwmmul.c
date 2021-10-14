/* This is a test program for kwmmul instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>


static __attribute__ ((noinline))
int32_t kwmmul (int32_t ra, int32_t rb)
{
  return __rv_kwmmul (ra, rb);
}

int
main ()
{
  int32_t a = kwmmul (0x8000000080000000, 0x8000000080000000);

  if (a != 0x7fffffff7fffffff)
    abort ();
  else
    exit (0);
}
