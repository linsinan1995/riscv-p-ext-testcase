/* This is a test program for add8 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv32gc_zpn -mabi=ilp32d -O2" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t add8 (uint32_t ra, uint32_t rb)
{
  return __rv_add8 (ra, rb);
}

static __attribute__ ((noinline))
uint8x4_t v_uadd8 (uint8x4_t ra, uint8x4_t rb)
{
  return __rv_v_uadd8 (ra, rb);
}

static __attribute__ ((noinline))
int8x4_t v_sadd8 (int8x4_t ra, int8x4_t rb)
{
  return __rv_v_sadd8 (ra, rb);
}

int
main ()
{
  uint32_t a = add8 (0x11223344, 0x55667788);
  uint8x4_t v_ua = v_uadd8 ((uint8x4_t) {0xff, 0xee, 0xdd, 0xcc},
			    (uint8x4_t) {0x1, 0xee, 0xdd, 0xcc});
  int8x4_t v_sa = v_sadd8 ((int8x4_t) {0x80, 0x7f, 0xbb, 0xaa},
			   (int8x4_t) {0x80, 0x7f, 0xbb, 0xaa});

  if (a != 0x6688aacc)
    abort ();
  else if (v_ua[0] != 0
	   || v_ua[1] != 0xdc
	   || v_ua[2] != 0xba
	   || v_ua[3] != 0x98)
    abort ();
  else if (v_sa[0] != 0
	   || v_sa[1] != (signed char) 0xfe
	   || v_sa[2] != 0x76
	   || v_sa[3] != 0x54)
    abort ();
  else
    exit (0);
}
