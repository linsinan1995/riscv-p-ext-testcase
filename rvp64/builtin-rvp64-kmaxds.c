/* This is a test program for kmaxds instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
int32_t kmaxds (uint32_t rd, uint32_t ra, uint32_t rb)
{
  return __rv__kmaxds (rd, ra, rb);
}

static __attribute__ ((noinline))
int32x2_t v_kmaxds (int32x2_t rd, int16x4_t ra, int16x4_t rb)
{
  return __rv__v_kmaxds (rd, ra, rb);
}

int
main ()
{
  int32_t va_p = 0x200000002;
  int32_t a = kmaxds (0x300000003, 0x8000000280000002, 0x8000000180000001);
  int32x2_t va = v_kmaxds ((int32x2_t) {0x3, 0x3},
			   (int16x4_t) {0xffff, 0x0002, 0xffff, 0x0002},
			   (int16x4_t) {0xffff, 0x0001, 0xffff, 0x0001});

  if (a != 0x800300008003)
    abort ();
  else if (va[0] != 0x2
	   || va[1] != 0x2)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif