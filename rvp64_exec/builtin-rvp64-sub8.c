/* This is a test program for sub8 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>
#include "test_utils.h"

static __attribute__ ((noinline))
uint64_t sub8 (uint64_t ra, uint64_t rb)
{
  return __rv_sub8 (ra, rb);
}

static __attribute__ ((noinline))
uint8x8_t v_usub8 (uint8x8_t ra, uint8x8_t rb)
{
  return __rv_v_usub8 (ra, rb);
}

static __attribute__ ((noinline))
int8x8_t v_ssub8 (int8x8_t ra, int8x8_t rb)
{
  return __rv_v_ssub8 (ra, rb);
}

int
main ()
{
  uint64_t a = sub8 (0x5566778855667788, 0x1122334411223344);
  uint8x8_t v_ua = v_usub8 ((uint8x8_t) {0xff, 0xee, 0xee, 0xcc, 0xff, 0xee, 0xee, 0xcc},
			    (uint8x8_t) {0x1, 0xee, 0xdd, 0xdd, 0x1, 0xee, 0xdd, 0xdd});
  int8x8_t v_sa = v_ssub8 ((int8x8_t) {0x81, 0x0, 0xdd, 0xaa, 0x81, 0x0, 0xdd, 0xaa},
			   (int8x8_t) {0x80, 0x1, 0xcc, 0xaa, 0x80, 0x1, 0xcc, 0xaa});

  if (a != 0x4444444444444444)
    abort ();
  else if (v_ua[0] != 0xfe
	   || v_ua[1] != 0
	   || v_ua[2] != 0x11
	   || v_ua[3] != 0xef
	   || v_ua[4] != 0xfe
	   || v_ua[5] != 0
	   || v_ua[6] != 0x11
	   || v_ua[7] != 0xef)
    abort ();
  else if (v_sa[0] != 1
	   || v_sa[1] != (signed char) 0xff
	   || v_sa[2] != 0x11
	   || v_sa[3] != 0
	   || v_sa[4] != 1
	   || v_sa[5] != (signed char) 0xff
	   || v_sa[6] != 0x11
	   || v_sa[7] != 0)
    abort ();
  else
    exit (0);
}
