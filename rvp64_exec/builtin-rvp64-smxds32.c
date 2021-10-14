/* This is a test program for smxds32 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>


static __attribute__ ((noinline))
int64_t smxds32 (uint64_t ra, uint64_t rb)
{
  return __rv_smxds32 (ra, rb);
}

static __attribute__ ((noinline))
int64_t v_smxds32 (int32x2_t ra, int32x2_t rb)
{
  return __rv_v_smxds32 (ra, rb);
}

int
main ()
{
  int64_t va_p = 0;
  int64_t a = smxds32 (0x8000000280000002, 0x8000000180000001);
  int64_t va = v_smxds32 ((int32x2_t) {0xffff0002, 0xffff0002},
		       (int32x2_t) {0xffff0001, 0xffff0001});

  if (a != 0)
    abort ();
  else if (va != va_p)
    abort ();
  else
    exit (0);
}
