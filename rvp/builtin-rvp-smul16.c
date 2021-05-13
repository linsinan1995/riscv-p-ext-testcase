/* This is a test program for smul16 instruction.  */
/* { dg-do run { target { riscv32*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpsf) && !defined(__riscv_32e)
static __attribute__ ((noinline))
uint64_t smul16 (uint32_t ra, uint32_t rb)
{
  return __rv__smul16 (ra, rb);
}

static __attribute__ ((noinline))
int32x2_t v_smul16 (int16x2_t ra, int16x2_t rb)
{
  return __rv__v_smul16 (ra, rb);
}

int
main ()
{
  uint64_t a = smul16 (0xffff0000, 0x0001ffff);
  int32x2_t va = v_smul16 ((int16x2_t) {0xffff, 0},
			   (int16x2_t) {0x0001, 0xffff});

  if (a != 0xffffffff00000000)
    abort ();
  else if (va[0] != 0xffffffff
           || va[1] != 0)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
