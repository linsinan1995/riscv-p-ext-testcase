/* This is a test program for scmplt16 instruction.  */

/* { dg-do run { target { riscv64*-*-* } } } */

#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

#if defined(__riscv_zpn) && !defined(__riscv_32e)
static __attribute__ ((noinline))
uint32_t scmplt16 (uint32_t ra, uint32_t rb)
{
  return __rv__scmplt16 (ra, rb);
}

static __attribute__ ((noinline))
uint16x4_t v_scmplt16 (int16x4_t ra, int16x4_t rb)
{
  return __rv__v_scmplt16 (ra, rb);
}

int
main ()
{
  uint16x4_t va_p = {0, 0xffff, 0, 0xffff};
  uint32_t a = scmplt16 (0xfffe0001fffe0001, 0xffff0000ffff0000);
  uint16x4_t va = v_scmplt16 ((int16x4_t) {0x7fff, 0x7ffe, 0x7fff, 0x7ffe},
			      (int16x4_t) {0x7ffe, 0x7fff, 0x7ffe, 0x7fff});

  if (a != 0xffff0000ffff0000)
    abort ();
  else if (!vec64_all_eq (u, 16, va_p, va))
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif