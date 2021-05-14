/* This is a test program for wsbh instruction.  */
/* { dg-do run { target { riscv64*-*-* } } } */
/* { dg-options "-O0" } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
uint64_t swap16 (uint64_t a)
{
  return __rv__swap16 (a);
}

static __attribute__ ((noinline))
uint16x4_t v_swap16 (uint16x4_t a)
{
  return __rv__v_swap16 (a);
}

int
main ()
{
  uint64_t a = 0x03020100;
  uint64_t b;

  b = swap16 (a);

  if (b != 0x02030001)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
