/* This is a test program for kmmawb.u instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zprv_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
int64_t kmmawbu (int64_t rd, int64_t ra, uint64_t rb)
{
  return __rv_kmmawb_u (rd, ra, rb);
}

static __attribute__ ((noinline))
int32x2_t v_kmmawbu (int32x2_t rd, int32x2_t ra, int16x4_t rb)
{
  return __rv_v_kmmawb_u (rd, ra, rb);
}

int
main ()
{
  int64_t a = kmmawbu (0, 0x8000000080000000, 0x8000000180000001);
  int32x2_t va = v_kmmawbu ((int32x2_t) {0, 0},
			    (int32x2_t) {0x80000000, 0x80000000},
			    (int16x4_t) {0x1, 0x8000, 0x1, 0x8000});

  if (a != 0xffff8000ffff8000)
    abort ();
  else if (va[0] != 0xffff8000
	   || va[1] != 0xffff8000)
    abort ();
  else
    exit (0);
}
