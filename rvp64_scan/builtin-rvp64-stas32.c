/* stas32 also appears on filename, so scan-assembler-times plus 1 */
/* This is a test program for stas32 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gc_zpn_zpsf -mabi=lp64d -O0" } */


#include <rvp_intrinsic.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint64_t uintXLEN_t;
typedef uint32x2_t vxUSI;
typedef int32x2_t vxSI;

static __attribute__ ((noinline))
uintXLEN_t foo(uintXLEN_t a, uintXLEN_t b) {
  return __rv_stas32 (a, b);
}

static __attribute__ ((noinline))
uintXLEN_t foo2(uintXLEN_t a, uintXLEN_t b) {
  return __rv_rstas32 (a, b);
}

static __attribute__ ((noinline))
uintXLEN_t foo3(uintXLEN_t a, uintXLEN_t b) {
  return __rv_urstas32 (a, b);
}

static __attribute__ ((noinline))
vxUSI foo4(vxUSI a, vxUSI b) {
  return __rv_v_ustas32 (a, b);
}

static __attribute__ ((noinline))
vxSI foo5(vxSI a, vxSI b) {
  return __rv_v_sstas32 (a, b);
}

static __attribute__ ((noinline))
vxSI foo6(vxSI a, vxSI b) {
  return __rv_v_rstas32 (a, b);
}

static __attribute__ ((noinline))
vxUSI foo7(vxUSI a, vxUSI b) {
  return __rv_v_urstas32 (a, b);
}

static __attribute__ ((noinline))
uintXLEN_t foo8(uintXLEN_t a, uintXLEN_t b) {
  return __rv_kstas32 (a, b);
}

static __attribute__ ((noinline))
vxSI foo9(vxSI a, vxSI b) {
  return __rv_v_kstas32 (a, b);
}

static __attribute__ ((noinline))
uintXLEN_t foo10(uintXLEN_t a, uintXLEN_t b) {
  return __rv_ukstas32 (a, b);
}

static __attribute__ ((noinline))
vxUSI foo11(vxUSI a, vxUSI b) {
  return __rv_v_ukstas32 (a, b);
}

/* { dg-final { scan-assembler-times "stas32" 4 } } */
/* { dg-final { scan-assembler-times "rstas32" 2 } } */
/* { dg-final { scan-assembler-times "urstas32" 2 } } */
/* { dg-final { scan-assembler-times "kstas32" 2 } } */
/* { dg-final { scan-assembler-times "ukstas32" 2 } } */
/* { dg-final { scan-assembler-times "builtin_riscv" 0 } } */
