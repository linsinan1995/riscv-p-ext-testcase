/* This is a test program for pkbt16 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zprv_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
uint64_t pkbt16 (uint64_t ra, uint64_t rb)
{
  return __rv_pkbt16 (ra, rb);
}

static __attribute__ ((noinline))
uint16x4_t v_pkbt16 (uint16x4_t ra, uint16x4_t rb)
{
  return __rv_v_pkbt16 (ra, rb);
}

int
main ()
{
  uint16x4_t va_p = {0xdddd, 0xaaaa, 0xdddd, 0xaaaa};
  uint64_t a = pkbt16 (0x1122334411223344, 0x5566778855667788);
  uint16x4_t va = v_pkbt16 ((uint16x4_t) {0xaaaa, 0xbbbb, 0xaaaa, 0xbbbb},
			    (uint16x4_t) {0xcccc, 0xdddd, 0xcccc, 0xdddd});

  if (a != 0x3344556633445566)
    abort ();
  else if (!vec_all_eq (ret, 16, va_p, va))
    abort ();
  else
    exit (0);
}
