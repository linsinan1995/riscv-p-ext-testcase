/* This is a test program for scmplt8 instruction.  */
/* { dg-do run { target { riscv32*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
uint32_t scmplt8 (uint32_t ra, uint32_t rb)
{
  return __rv__scmplt8 (ra, rb);
}

static __attribute__ ((noinline))
uint8x4_t v_scmplt8 (int8x4_t ra, int8x4_t rb)
{
  return __rv__v_scmplt8 (ra, rb);
}

int
main ()
{
  uint32_t a = scmplt8 (0xfefe0101, 0xffff0000);
  uint8x4_t va = v_scmplt8 ((int8x4_t) {0x7e, 0x7e, 0x01, 0x01},
			    (int8x4_t) {0x7f, 0x7f, 0x00, 0x00});

  if (a != 0xffff0000)
    abort ();
  else if (va[0] != 0xff
           || va[1] != 0xff
           || va[2] != 0
	   || va[3] != 0)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
