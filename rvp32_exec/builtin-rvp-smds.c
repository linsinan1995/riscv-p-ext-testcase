/* This is a test program for smds instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv32gc_zpn -mabi=ilp32d -O2" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int32_t smds (uint32_t ra, uint32_t rb)
{
  return __rv_smds (ra, rb);
}

static __attribute__ ((noinline))
int32_t v_smds (int16x2_t ra, int16x2_t rb)
{
  return __rv_v_smds (ra, rb);
}

int
main ()
{
  int32_t va_p = 1;
  int32_t a = smds (0x80000002, 0x80000001);
  int32_t va = v_smds ((int16x2_t) {0xffff, 0x0002},
		    (int16x2_t) {0xffff, 0x0001});

  if (a != 0x3ffffffe)
    abort ();
  else if (va != va_p)
    abort ();
  else
    exit (0);
}
