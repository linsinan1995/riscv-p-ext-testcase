/* This is a test program for kslra32 instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zprv) && !defined(__riscv_32e)
static __attribute__ ((noinline))
uint32_t kslra32 (uint32_t ra, uint32_t rb)
{
  return __rv__kslra32 (ra, rb);
}

static __attribute__ ((noinline))
int32x2_t v_kslra32 (int32x2_t ra, uint32_t rb)
{
  return __rv__v_kslra32 (ra, rb);
}

int
main ()
{
  int32x2_t va_p = {0x7fffffff, 0x7fffffff};
  uint32_t a = kslra32 (0x0f00f0000f00f000, 12);
  int32x2_t va = v_kslra32 ((int32x2_t) {0x7fff8000, 0x7fff8000}, 12);

  if (a != 0x7fffffff7fffffff)
    abort ();
  else if (va[0] != va_p[0]
	   || va[1] != va_p[1])
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
