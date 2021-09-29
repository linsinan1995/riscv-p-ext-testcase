/* This is a test program for sll16 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zprv_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
uint64_t sll16 (uint64_t ra, uint32_t rb)
{
  return __rv_sll16 (ra, rb);
}

static __attribute__ ((noinline))
uint16x4_t v_sll16 (uint16x4_t ra, uint32_t rb)
{
  return __rv_v_sll16 (ra, rb);
}

int
main ()
{
  uint16x4_t va_p = {0xfff0, 0, 0xfff0, 0};
  uint64_t a = sll16 (0x0f00f0000f00f000, 4);
  uint16x4_t va = v_sll16 ((uint16x4_t) {0x7fff, 0x8000, 0x7fff, 0x8000}, 4);

  if (a != 0xf0000000f0000000)
    abort ();
  else if (!vec_all_eq (ret, 16, va_p, va))
    abort ();
  else
    exit (0);
}
