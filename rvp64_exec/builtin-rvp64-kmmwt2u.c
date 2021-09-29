/* This is a test program for kmmwt2u instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zprv_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
int64_t kmmwt2u (int64_t ra, uint64_t rb)
{
  return __rv_kmmwt2_u (ra, rb);
}

static __attribute__ ((noinline))
int32x2_t v_kmmwt2u (int32x2_t ra, int16x4_t rb)
{
  return __rv_v_kmmwt2_u (ra, rb);
}

int
main ()
{
  int64_t a = kmmwt2u (0x8000000080000000, 0x8000000180000001);
  int32x2_t va = v_kmmwt2u ((int32x2_t) {0x80000000, 0x80000000},
			    (int16x4_t) {0x1, 0x8000, 0x1, 0x8000});

  if (a != 0x7fffffff7fffffff)
    abort ();
  else if (va[0] != 0x7fffffff
	   || va[1] != 0x7fffffff)
    abort ();
  else
    exit (0);
}
