/* This is a test program for add8 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>


static __attribute__ ((noinline))
uint64_t uclip32 (int64_t ra)
{
  return __rv_uclip32 (ra, 5);
}

int
main ()
{
  int64_t a = uclip32 (0x0000000100000100);

  if (a != 0x10000001f)
    abort ();
  else
    exit (0);
}
