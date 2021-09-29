/* This is a test program for cmpeq8 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv32gc_zpn -mabi=ilp32d -O2" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
uint32_t cmpeq8 (uint32_t ra, uint32_t rb)
{
  return __rv_cmpeq8 (ra, rb);
}

static __attribute__ ((noinline))
uint8x4_t v_scmpeq8 (int8x4_t ra, int8x4_t rb)
{
  return __rv_v_scmpeq8 (ra, rb);
}

static __attribute__ ((noinline))
uint8x4_t v_ucmpeq8 (uint8x4_t ra, uint8x4_t rb)
{
  return __rv_v_ucmpeq8 (ra, rb);
}

int
main ()
{
  uint32_t a = cmpeq8 (0xffff0000, 0xffff0101);
  uint8x4_t v_sa = v_scmpeq8 ((int8x4_t) { 0x7f, 0x7f, 0x01, 0x01},
			      (int8x4_t) { 0x7f, 0x7f, 0x00, 0x00});
  uint8x4_t v_ua = v_ucmpeq8 ((uint8x4_t) { 0x7f, 0x7f, 0x01, 0x01},
			      (uint8x4_t) { 0x7f, 0x7f, 0x00, 0x00});

  if (a != 0xffff0000)
    abort ();
  else if (v_sa[0] != 0xff
           || v_sa[1] != 0xff
           || v_sa[2] != 0
	   || v_sa[3] != 0)
    abort ();
  else if (v_ua[0] != 0xff
           || v_ua[1] != 0xff
           || v_ua[2] != 0
	   || v_ua[3] != 0)
    abort ();
  else
    exit (0);
}
