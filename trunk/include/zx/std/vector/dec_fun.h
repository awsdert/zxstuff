#pragma once
#ifndef ZXV_DEC
#include "../lib.h"
#include "../math.h"

#define ZXSOBJ( NAME ) struct NAME##_struct
#define ZXV_OBJ( NAME, T ) \
  typedef ZXSOBJ( NAME ) \
  { \
    zxVECTOR m_core; \
    T       *m_data; \
  } NAME

#define ZXV___INIT(     NAME, T, DLL, FUN  ) DLL void \
  FUN( NAME *src, T const *cpy, size_t count )
#define ZXV__INIT(      NAME, T, DLL, CALL ) \
  ZXV___INIT( NAME, T, DLL, CALL NAME##__init )

#define ZXV___INITCPY(  NAME,    DLL, FUN  ) DLL void \
  FUN( NAME *src, NAME const *cpy )
#define ZXV__INITCPY(   NAME,    DLL, CALL ) \
  ZXV___INITCPY( NAME, DLL, CALL NAME##__initCpy )

#define ZXV___KILL(     NAME,    DLL, FUN  ) DLL void \
  FUN( NAME *src )
#define ZXV__KILL(      NAME,    DLL, CALL ) \
  ZXV___KILL( NAME, DLL, CALL NAME##__kill )

#define ZXV__TMPOBJ(    NAME, T, DLL, FUN  ) DLL NAME \
  FUN( T *src )
#define ZXV_TMPOBJ(     NAME, T, DLL, CALL ) \
  ZXV__TMPOBJ( NAME, T, DLL, CALL NAME##_tmpobj )

#define ZXV__SIZE(      NAME,    DLL, FUN  ) DLL size_t \
  FUN( NAME const *src )
#define ZXV_SIZE(       NAME,    DLL, CALL ) \
  ZXV__SIZE( NAME, DLL, CALL NAME##_size )

#define ZXV__MAX_SIZE(  NAME,    DLL, FUN  ) DLL size_t \
  FUN( NAME const *src )
#define ZXV_MAX_SIZE(   NAME,    DLL, CALL ) \
  ZXV__MAX_SIZE( NAME, DLL, CALL NAME##_max_size )

#define ZXV__RESIZE(    NAME, T, DLL, FUN  ) DLL void \
  FUN( NAME       *src, size_t setCount, T const setNew )
#define ZXV_RESIZE(     NAME, T, DLL, CALL ) \
  ZXV__RESIZE( NAME, T, DLL, CALL NAME##_resize )

#define ZXV__CAPACITY(  NAME,    DLL, FUN  ) DLL size_t \
  FUN( NAME const *src )
#define ZXV_CAPACITY(   NAME,    DLL, CALL ) \
  ZXV__CAPACITY( NAME, DLL, CALL NAME##_capacity )

#define ZXV__EMPTY(     NAME,    DLL, FUN  ) DLL bool \
  FUN( NAME const *src )
#define ZXV_EMPTY(      NAME,    DLL, CALL ) \
  ZXV__EMPTY( NAME, DLL, NAME##_empty )

#define ZXV__RESERVE(   NAME,    DLL, FUN  ) DLL void \
  FUN( NAME       *src, size_t minSize )
#define ZXV_RESERVE(    NAME,    DLL, CALL ) \
  ZXV__RESERVE( NAME, DLL, CALL NAME##_reserve )

#define ZXV__GROW(      NAME, T, DLL, FUN  ) DLL void \
  FUN( NAME       *src, size_t setCount, T const setNew )
#define ZXV_GROW(       NAME, T, DLL, CALL ) \
  ZXV__GROW( NAME, T, DLL, CALL NAME##_grow )

#define ZXV__SHRINK(    NAME,    DLL, FUN  ) DLL void \
  FUN( NAME       *src, size_t setCount )
#define ZXV_SHRINK(         NAME,    DLL, CALL ) \
  ZXV__SHRINK( NAME, DLL, CALL NAME##_shrink )

#define ZXV__SHRINK_TO_FIT( NAME,    DLL, FUN  ) DLL void \
  FUN( NAME       *src )
#define ZXV_SHRINK_TO_FIT(  NAME,    DLL, CALL ) \
  ZXV__SHRINK_TO_FIT( NAME, DLL, CALL NAME##_shrink_to_fit )

#define ZXV__ASSIGN ZXV__RESIZE
#define ZXV_ASSIGN(         NAME, T, DLL, CALL ) \
  ZXV__ASSIGN( NAME, T, DLL, CALL NAME##_assign )

#define ZXV__APPEND(        NAME,    DLL, FUN  ) DLL void \
  FUN( NAME *src, NAME const *cpy, size_t pos )
#define ZXV_APPEND(         NAME,    DLL, CALL ) \
  ZXV__APPEND( NAME, DLL, CALL NAME##_append )

#define ZXV__PUSH(          NAME, T, DLL, FUN  ) DLL bool \
  FUN( NAME *src, T const cpy, size_t pos, bool unique )
#define ZXV_PUSH(           NAME, T, DLL, CALL ) \
  ZXV__PUSH( NAME, T, DLL, CALL NAME##_push )

#define ZXV__PUSH_BACK(     NAME, T, DLL, FUN  ) DLL bool \
  FUN( NAME *src, T const cpy, bool unique )
#define ZXV_PUSH_BACK(      NAME, T, DLL, CALL ) \
  ZXV__PUSH_BACK( NAME, T, DLL, CALL NAME##_push_back )

#define ZXV__POP(           NAME, T, DLL, FUN  ) DLL void \
  FUN( NAME *src, T const cmp, size_t first, size_t last )
#define ZXV_POP(            NAME, T, DLL, CALL ) \
  ZXV__POP( NAME, T, DLL, CALL NAME##_pop )

#define ZXV__POP_BACK(      NAME,    DLL, FUN  ) DLL void \
  FUN( NAME       *src )
#define ZXV_POP_BACK(       NAME,    DLL, CALL ) \
  ZXV__POP_BACK( NAME, DLL, CALL NAME##_pop_back )

#define ZXV__INSERT(        NAME,    DLL, FUN  ) DLL void \
  FUN( NAME *src, NAME const *cpy, size_t pos )
#define ZXV_INSERT(         NAME,    DLL, CALL ) \
  ZXV__INSERT( NAME, DLL, CALL NAME##_insert )

#define ZXV__ERASE(         NAME,    DLL, FUN  ) DLL void \
  FUN( NAME *src, size_t first, size_t last )
#define ZXV_ERASE(          NAME,    DLL, CALL ) \
  ZXV__ERASE( NAME, DLL, CALL NAME##_erase )

#define ZXV__SWAP(          NAME,    DLL, FUN  ) DLL void \
  FUN( NAME *src, NAME *dst )
#define ZXV_SWAP(           NAME,    DLL, CALL ) \
  ZXV__SWAP( NAME, DLL, CALL NAME##_swap )

#define ZXV__CLEAR(         NAME,    DLL, FUN  ) DLL void \
  FUN( NAME *src )
#define ZXV_CLEAR(          NAME,    DLL, CALL ) \
  ZXV__CLEAR( NAME, DLL, CALL NAME##_clear )

#define ZXV__REVERSE(       NAME,    DLL, FUN  ) DLL void \
  FUN( NAME *src )
#define ZXV_REVERSE(        NAME,    DLL, CALL ) \
  ZXV__CLEAR( NAME, DLL, CALL NAME##_reverse )

#define ZXV__COPY(          NAME, T, DLL, FUN  ) DLL size_t \
  FUN( NAME const *src, T *dst, \
    size_t const count, size_t const from )
#define ZXV_COPY(           NAME, T, DLL, CALL ) \
  ZXV__COPY( NAME, T, DLL, CALL NAME##_copy )

#define ZXV__AT(            NAME, T, DLL, FUN  ) DLL T* \
  FUN( NAME const *src, size_t i )
#define ZXV_AT(             NAME, T, DLL, CALL ) \
  ZXV__AT( NAME, T, DLL, CALL NAME##_at )

#define ZXV__ISEQUAL(       NAME,    DLL, FUN  ) DLL bool \
  FUN( NAME const *src, NAME const *cmp, size_t *I )
#define ZXV_ISEQUAL(        NAME,    DLL, CALL ) \
  ZXV__ISEQUAL( NAME, DLL, CALL NAME##_isEqual )

#define ZXV__OPEQL(        NAME,    DLL, FUN  ) DLL NAME* \
  FUN( NAME *src, NAME const *cpy )
#define ZXV_OPEQL(         NAME,    DLL, CALL ) \
  ZXV__OPEQL( NAME, DLL, CALL NAME##_opEql )

#define ZXV__OPADD(         NAME,    DLL, FUN  ) DLL NAME* \
  FUN( NAME *src, NAME const *cpy )
#define ZXV_OPADD(          NAME,    DLL, CALL ) \
  ZXV__OPADD( NAME, DLL, CALL NAME##_opAdd )

#define ZXV__OPMVL ZXV__OPADD
#define ZXV_OPMVL(          NAME,    DLL, CALL ) \
  ZXV__OPMVL( NAME, DLL, CALL NAME##_opMvl )

#define ZXV__CMP(           NAME,    DLL, FUN  ) DLL bool \
  FUN( NAME const *src, NAME const *cmp )
#define ZXV_CMPEQ(          NAME,    DLL, CALL ) \
  ZXV__CMP( NAME, DLL, CALL NAME##_cmpEQ )
#define ZXV_CMPNE(          NAME,    DLL, CALL ) \
  ZXV__CMP( NAME, DLL, CALL NAME##_cmpNE )

#define ZXV__DEC( NAME, T, T2, DLL, CALL ) \
  ZXV__INITCPY(      NAME,     DLL, CALL ); \
  ZXV__KILL(         NAME,     DLL, CALL ); \
  ZXV_TMPOBJ(        NAME, T2, DLL, CALL ); \
  ZXV_SIZE(          NAME,     DLL, CALL ); \
  ZXV_MAX_SIZE(      NAME,     DLL, CALL ); \
  ZXV_RESIZE(        NAME, T,  DLL, CALL ); \
  ZXV_CAPACITY(      NAME,     DLL, CALL ); \
  ZXV_EMPTY(         NAME,     DLL, CALL ); \
  ZXV_RESERVE(       NAME,     DLL, CALL ); \
  ZXV_GROW(          NAME, T,  DLL, CALL ); \
  ZXV_SHRINK(        NAME,     DLL, CALL ); \
  ZXV_SHRINK_TO_FIT( NAME,     DLL, CALL ); \
  ZXV__ASSIGN(       NAME, T, static, \
    (CALL *NAME##_assign) ) = NAME##_resize; \
  ZXV_APPEND(        NAME,     DLL, CALL ); \
  ZXV_PUSH(          NAME, T,  DLL, CALL ); \
  ZXV_PUSH_BACK(     NAME, T,  DLL, CALL ); \
  ZXV_POP(           NAME, T,  DLL, CALL ); \
  ZXV_POP_BACK(      NAME,     DLL, CALL ); \
  ZXV_INSERT(        NAME,     DLL, CALL ); \
  ZXV_ERASE(         NAME,     DLL, CALL ); \
  ZXV_SWAP(          NAME,     DLL, CALL ); \
  ZXV_CLEAR(         NAME,     DLL, CALL ); \
  ZXV_REVERSE(       NAME,     DLL, CALL ); \
  ZXV_COPY(          NAME, T2, DLL, CALL ); \
  ZXV_AT(            NAME, T2, DLL, CALL ); \
  ZXV_ISEQUAL(       NAME,     DLL, CALL ); \
  ZXV_OPEQL(         NAME,     DLL, CALL ); \
  ZXV_OPADD(         NAME,     DLL, CALL ); \
  ZXV__OPMVL(        NAME, static,  \
    (CALL *NAME##_opMvl) ) = NAME##_opAdd; \
  ZXV_CMPEQ(         NAME,     DLL, CALL ); \
  ZXV_CMPNE(         NAME,     DLL, CALL )

#define ZXV_DEC( NAME, T, DLL, CALL ) \
  ZXV__INIT(         NAME, T, DLL, CALL ); \
  ZXV__DEC(       NAME, T, T, DLL, CALL )

#define ZXV__NS_DEC( NAME, T, T2, CALL ) \
  NAME const def; \
  ZXV___INITCPY(      NAME,,      (CALL *_initCpy)      ); \
  ZXV___KILL(         NAME,,      (CALL *_kill)         ); \
  ZXV__TMPOBJ(        NAME, T2,,  (CALL *tmpobj)        ); \
  ZXV__SIZE(          NAME,,      (CALL *size)          ); \
  ZXV__MAX_SIZE(      NAME,,      (CALL *max_size)      ); \
  ZXV__RESIZE(        NAME, T,,   (CALL *resize)        ); \
  ZXV__CAPACITY(      NAME,,      (CALL *capacity)      ); \
  ZXV__EMPTY(         NAME,,      (CALL *empty)         ); \
  ZXV__RESERVE(       NAME,,      (CALL *reserve)       ); \
  ZXV__GROW(          NAME, T,,   (CALL *grow)          ); \
  ZXV__SHRINK(        NAME,,      (CALL *shrink)        ); \
  ZXV__SHRINK_TO_FIT( NAME,,      (CALL *shrink_to_fit) ); \
  ZXV__ASSIGN(        NAME, T,,   (CALL *assign)        ); \
  ZXV__APPEND(        NAME,,      (CALL *append)        ); \
  ZXV__PUSH(          NAME, T,,   (CALL *push)          ); \
  ZXV__PUSH_BACK(     NAME, T,,   (CALL *push_back)     ); \
  ZXV__POP(           NAME, T,,   (CALL *pop)           ); \
  ZXV__POP_BACK(      NAME,,      (CALL *pop_back)      ); \
  ZXV__INSERT(        NAME,,      (CALL *insert)        ); \
  ZXV__ERASE(         NAME,,      (CALL *erase)         ); \
  ZXV__SWAP(          NAME,,      (CALL *swap)          ); \
  ZXV__CLEAR(         NAME,,      (CALL *clear)         ); \
  ZXV__REVERSE(       NAME,,      (CALL *reverse)       ); \
  ZXV__COPY(          NAME, T2,,  (CALL *copy)          ); \
  ZXV__AT(            NAME, T2,,  (CALL *at)            ); \
  ZXV__ISEQUAL(       NAME,,      (CALL *isEqual)       ); \
  ZXV__OPEQL(         NAME,,      (CALL *opEql)         ); \
  ZXV__OPADD(         NAME,,      (CALL *opAdd)         ); \
  ZXV__OPMVL(         NAME,,      (CALL *opMvl)         ); \
  ZXV__CMP(           NAME,,      (CALL *cmpEQ)         ); \
  ZXV__CMP(           NAME,,      (CALL *cmpNE)         )

#define ZXV_NS_DEC( NAME, T, CALL ) \
  ZXV___INIT(         NAME, T,,   (CALL *_init)         ); \
  ZXV__NS_DEC(        NAME, T, T, CALL )

#endif
