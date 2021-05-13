/* add64 also appears on filename, so scan-assembler-times plus 1 */
/* add64 will generate 'add' in rv64p */
/* This is a test program for add64 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options } "-march=rv64i_zpn_zprv_zpsf -mabi=lp64 -O2" */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

static __attribute__ ((noinline))
int64_t ddas (int64_t ra, int64_t rb)
{
  return __rv__sadd64 (ra, rb);
}

static __attribute__ ((noinline))
uint64_t ddau (uint64_t ra, uint64_t rb)
{
  return __rv__uadd64 (ra, rb);
}
/* { dg-final { scan-assembler-times "add64" 1 } } */