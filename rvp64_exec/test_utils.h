#define vec_all_eq(ret, size, vec1, vec2) \
do                                            \
{                                             \
  unsigned int __i=0;                         \
  bool __ret=true;                            \
  for (__i=0; __i < __riscv_xlen/size; __i++) \
    __ret &= (vec1[__i] == vec2[__i]);        \
  ret=__ret                                   \
} while (0)                                   \
