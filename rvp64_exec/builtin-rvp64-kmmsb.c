/* This is a test program for kmmsb instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zprv_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
int64_t kmmsb (int64_t rd, int64_t ra, int64_t rb)
{
  return __rv_kmmsb (rd, ra, rb);
}

int
main ()
{
  int64_t a = kmmsb (0, 0x8000000080000000, 0x8000000080000000);

  if (a != 0xc0000000c0000000)
    abort ();
  else
    exit (0);
}
