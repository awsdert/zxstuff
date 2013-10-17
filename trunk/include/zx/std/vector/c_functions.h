#ifndef ZXV_FUN_H
#define ZXV_FUN_H

#define ZXV__SIZE(          NAME,    DLL, FUN ) DLL size_t \
  FUN##( NAME const *src )

#define ZXV_SIZE( NAME, DLL ) \
  ZXV__SIZE( NAME, DLL, zxv_##NAME##_size )

#define ZXV__MAX_SIZE(      NAME,    DLL, FUN ) DLL size_t \
  FUN##( NAME const *src )

#define ZXV_MAX_SIZE( NAME, DLL ) \
  ZXV__MAX_SIZE( NAME, DLL, zxv_##NAME##_max_size )

#define ZXV__RESIZE(        NAME, T, DLL, FUN ) DLL void \
  FUN##( NAME       *src, size_t setCount, T const setNew )

#define ZXV_RESIZE( NAME, T, DLL ) \
  ZXV__RESIZE( NAME, T, DLL, zxv_##NAME##_resize )

#define ZXV__CAPACITY(          NAME,    DLL, FUN ) DLL size_t \
  FUN##( NAME const *src )

#define ZXV_CAPACITY(      NAME,    DLL ) \
  ZXV__CAPACITY( NAME, DLL, zxv_##NAME##_capacity )

#define ZXV__EMPTY(         NAME,    DLL, FUN ) DLL bool \
  FUN##( NAME const *src )

#define ZXV_EMPTY( NAME, DLL ) \
  ZXV__EMPTY( NAME, DLL, zxv_##NAME##_empty )

#define ZXV__RESERVE(       NAME,    DLL, FUN ) DLL void \
  FUN##( NAME       *src, size_t minSize )

#define ZXV_RESERVE( NAME, DLL ) \
  ZXV__RESERVE( NAME, DLL, zxv_##NAME##_reserve )

#define ZXV__GROW(        NAME, T, DLL, FUN ) DLL void \
  FUN##( NAME       *src, size_t setCount, T const setNew )

#define ZXV_GROW(          NAME, T, DLL ) \
  ZXV__GROW( NAME, T, DLL, zxv_##NAME##_grow )

#define ZXV__SHRINK(        NAME,    DLL, FUN ) DLL void \
  FUN##( NAME       *src, size_t setCount )

#define ZXV_SHRINK( NAME, DLL ) \
  ZXV__SHRINK( NAME, DLL, zxv_##NAME##_shrink )

#define ZXV__SHRINK_TO_FIT( NAME,    DLL, FUN ) DLL void \
  FUN##( NAME       *src )

#define ZXV_SHRINK_TO_FIT( NAME,    DLL ) \
  ZXV_SHRINK_TO_FIT( NAME, DLL, zxv_##NAME##_shrink_to_fit )

#define ZXV__ASSIGN(        NAME, T, DLL, FUN ) DLL void \
  FUN##( NAME       *src, size_t setCount, T const setNew )

#define ZXV_ASSIGN( NAME, T, DLL ) \
  ZXV__RESIZE( NAME, T, DLL, zxv_##NAME##_assign )

#define ZXV__APPEND( NAME, DLL, FUN ) DLL void \
  FUN##( NAME *src, NAME const *cpy, size_t pos )

#define ZXV_APPEND( NAME, DLL ) \
  ZXV__APPEND( NAME, DLL, zxv_##NAME##_append )

#define ZXV__PUSH_BACK( NAME, DLL, FUN ) DLL bool \
  FUN##( NAME *src, NAME const *cpy )

#define ZXV_PUSH_BACK( NAME, DLL ) \
  ZXV__PUSH_BACK( NAME, DLL, zxv_##NAME##_push_back )

#define ZXV__POP_BACK( NAME,    DLL, FUN ) DLL void \
  FUN##( NAME       *src )

#define ZXV_POP_BACK( NAME,    DLL ) \
  ZXV_SHRINK_TO_FIT( NAME, DLL, zxv_##NAME##_pop_back )

#define ZXV__INSERT( NAME, DLL, FUN ) DLL void \
  FUN##( NAME *src, NAME const *cpy, size_t pos )

#define ZXV_INSERT( NAME, DLL ) \
  ZXV__APPEND( NAME, DLL, zxv_##NAME##_insert )

#define ZXV__AT(            NAME, T, DLL, FUN ) DLL T* \
  FUN##( NAME const *src, size_t i )

#define ZXV_AT( NAME, T, DLL ) \
  ZXV__AT( NAME, T, DLL, zxv_##NAME##_at )

#define ZXV__OPADD( NAME, DLL, FUN ) DLL NAME* \
  FUN##( NAME *src, NAME const *cpy )

#define ZXV_OPADD( NAME, DLL ) \
  ZXV__OPADD( NAME, DLL, zxv_##NAME##_opAdd )

#define ZXV__OPMVL( NAME, DLL, FUN ) DLL NAME* \
  FUN##( NAME *src, NAME const *cpy )

#define ZXV_OPMVL( NAME, DLL ) \
  ZXV__OPMVL( NAME, DLL, zxv_##NAME##_opMvl )

#endif