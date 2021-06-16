/* This is a test program for smmul instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zprv_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
int32_t smmul (int32_t ra, int32_t rb)
{
  return __rv_smmul (ra, rb);
}

int
main ()
{
  int32_t a = smmul (0x8000000080000000, 0x8000000080000000);

  if (a != 0x4000000040000000)
    abort ();
  else
    exit (0);
}
