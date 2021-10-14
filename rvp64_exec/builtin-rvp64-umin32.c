/* This is a test program for umin32 instruction.  */
/* { dg-do run } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O2" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>


static __attribute__ ((noinline))
uint64_t umin32 (uint64_t ra, uint64_t rb)
{
  return __rv_umin32 (ra, rb);
}

static __attribute__ ((noinline))
uint32x2_t v_umin32 (uint32x2_t ra, uint32x2_t rb)
{
  return __rv_v_umin32 (ra, rb);
}

int
main ()
{
  uint32x2_t va_p = {0x7ffe1000, 0x7ffe1000};
  uint64_t a = umin32 (0xfffe0001fffe0001, 0xffff0000ffff0000);
  uint32x2_t va = v_umin32 ((uint32x2_t) {0x7fff0000, 0x7fff0000},
			    (uint32x2_t) {0x7ffe1000, 0x7ffe1000});
  if (a != 0xfffe0001fffe0001)
    abort ();
  else if (va[0] != va_p[0]
	   || va[1] != va_p[1])
    abort ();
  else
    exit (0);
}
