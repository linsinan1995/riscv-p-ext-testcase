/* This is a test program for sra8 instruction.  */
/* { dg-do run { target { riscv32*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
uint32_t sra8 (uint32_t ra, uint32_t rb)
{
  return __rv__sra8 (ra, rb);
}

static __attribute__ ((noinline))
int8x4_t v_sra8 (int8x4_t ra, uint32_t rb)
{
  return __rv__v_sra8 (ra, rb);
}

int
main ()
{
  uint32_t a = sra8 (0x011223344, 4);
  int8x4_t va = v_sra8 ((int8x4_t) {0xff, 0xee, 0xdd, 0xcc}, 4);

  if (a != 0x1020304)
    abort ();
  else if (va[0] != (signed char) 0xff
	   || va[1] != (signed char) 0xfe
	   || va[2] != (signed char) 0xfd
	   || va[3] != (signed char) 0xfc)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif