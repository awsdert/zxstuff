#pragma once
#ifndef ZXV_DEC

#define ZXSOBJ( NAME ) struct NAME##_struct
#define ZXV_OBJ( NAME, T ) \
  typedef ZXSOBJ( NAME ) \
  { \
    zxVECTOR m_core; \
    T       *m_data; \
  } NAME

#define ZXV___INIT( NAME, T, DLL, FUN ) DLL void \
  FUN( NAME *src, T const *cpy, size_t count )

#define ZXV__INIT( NAME, T, DLL ) \
  ZXV___INIT( NAME, T, DLL, NAME##__init )

#define ZXV___INITCPY( NAME, DLL, FUN ) DLL void \
  FUN( NAME *src, NAME const *cpy )

#define ZXV__INITCPY( NAME, DLL ) \
  ZXV___INITCPY( NAME, DLL, NAME##__initCpy )

#define ZXV___KILL( NAME, DLL, FUN ) DLL void \
  FUN( NAME *src )

#define ZXV__KILL( NAME, DLL ) \
  ZXV___KILL( NAME, DLL, NAME##__kill )

#define ZXV__TMPOBJ( NAME, T, DLL, FUN  ) DLL NAME \
  FUN( T *src )
#define ZXV_TMPOBJ( NAME, T, DLL ) \
  ZXV__TMPOBJ( NAME, T, DLL, NAME##_tmpobj )

#define ZXV__SIZE(          NAME,    DLL, FUN ) DLL size_t FUN( NAME const *src )
#define ZXV_SIZE( NAME, DLL ) ZXV__SIZE( NAME, DLL, NAME##_size )
#define ZXV__MAX_SIZE(      NAME,    DLL, FUN ) DLL size_t FUN( NAME const *src )
#define ZXV_MAX_SIZE( NAME, DLL ) ZXV__MAX_SIZE( NAME, DLL, NAME##_max_size )

#define ZXV__RESIZE(        NAME, T, DLL, FUN ) DLL void \
  FUN( NAME       *src, size_t setCount, T const setNew )

#define ZXV_RESIZE( NAME, T, DLL ) \
  ZXV__RESIZE( NAME, T, DLL, NAME##_resize )

#define ZXV__CAPACITY(          NAME,    DLL, FUN ) DLL size_t FUN( NAME const *src )
#define ZXV_CAPACITY(      NAME,    DLL ) ZXV__CAPACITY( NAME, DLL, NAME##_capacity )

#define ZXV__EMPTY(         NAME,    DLL, FUN ) DLL bool FUN( NAME const *src )
#define ZXV_EMPTY( NAME, DLL ) ZXV__EMPTY( NAME, DLL, NAME##_empty )

#define ZXV__RESERVE(       NAME,    DLL, FUN ) DLL void \
  FUN( NAME       *src, size_t minSize )

#define ZXV_RESERVE( NAME, DLL ) \
  ZXV__RESERVE( NAME, DLL, NAME##_reserve )

#define ZXV__GROW(        NAME, T, DLL, FUN ) DLL void \
  FUN( NAME       *src, size_t setCount, T const setNew )

#define ZXV_GROW(          NAME, T, DLL ) \
  ZXV__GROW( NAME, T, DLL, NAME##_grow )

#define ZXV__SHRINK(        NAME,    DLL, FUN ) DLL void \
  FUN( NAME       *src, size_t setCount )

#define ZXV_SHRINK( NAME, DLL ) \
  ZXV__SHRINK( NAME, DLL, NAME##_shrink )

#define ZXV__SHRINK_TO_FIT( NAME,    DLL, FUN ) DLL void \
  FUN( NAME       *src )

#define ZXV_SHRINK_TO_FIT( NAME,    DLL ) \
  ZXV__SHRINK_TO_FIT( NAME, DLL, NAME##_shrink_to_fit )

#define ZXV__ASSIGN(        NAME, T, DLL, FUN ) DLL void \
  FUN( NAME       *src, size_t setCount, T const setNew )

#define ZXV_ASSIGN( NAME, T, DLL ) \
  ZXV__RESIZE( NAME, T, DLL, NAME##_assign )

#define ZXV__APPEND( NAME, DLL, FUN ) DLL void \
  FUN( NAME *src, NAME const *cpy, size_t pos )

#define ZXV_APPEND( NAME, DLL ) \
  ZXV__APPEND( NAME, DLL, NAME##_append )

#define ZXV__PUSH( NAME, T, DLL, FUN ) DLL bool \
  FUN( NAME *src, T const cpy, size_t pos, bool unique )

#define ZXV_PUSH( NAME, T, DLL ) \
  ZXV__PUSH( NAME, T, DLL, NAME##_push )

#define ZXV__PUSH_BACK( NAME, T, DLL, FUN ) DLL bool \
  FUN( NAME *src, T const cpy, bool unique )

#define ZXV_PUSH_BACK( NAME, T, DLL ) \
  ZXV__PUSH_BACK( NAME, T, DLL, NAME##_push_back )

#define ZXV__POP( NAME, T, DLL, FUN ) DLL void \
  FUN( NAME *src, T const cmp, size_t first, size_t last )

#define ZXV_POP( NAME, T, DLL ) \
  ZXV__POP( NAME, T, DLL, NAME##_pop )

#define ZXV__POP_BACK( NAME,    DLL, FUN ) DLL void \
  FUN( NAME       *src )

#define ZXV_POP_BACK( NAME,    DLL ) \
  ZXV__POP_BACK( NAME, DLL, NAME##_pop_back )

#define ZXV__INSERT( NAME, DLL, FUN ) DLL void \
  FUN( NAME *src, NAME const *cpy, size_t pos )

#define ZXV_INSERT( NAME, DLL ) \
  ZXV__INSERT( NAME, DLL, NAME##_insert )

#define ZXV__ERASE( NAME, DLL, FUN ) DLL void \
  FUN( NAME *src, size_t first, size_t last )

#define ZXV_ERASE( NAME, DLL ) \
  ZXV__ERASE( NAME, DLL, NAME##_erase )

#define ZXV__SWAP( NAME, DLL, FUN ) DLL void \
  FUN( NAME *src, NAME *dst )

#define ZXV_SWAP( NAME, DLL ) \
  ZXV__SWAP( NAME, DLL, NAME##_swap )

#define ZXV__CLEAR( NAME, DLL, FUN ) DLL void \
  FUN( NAME *src )

#define ZXV_CLEAR( NAME, DLL ) \
  ZXV__CLEAR( NAME, DLL, NAME##_clear )

#define ZXV__REVERSE( NAME, DLL, FUN ) DLL void \
  FUN( NAME *src )

#define ZXV_REVERSE( NAME, DLL ) \
  ZXV__CLEAR( NAME, DLL, NAME##_reverse )

#define ZXV__COPY( NAME, T, DLL, FUN ) DLL size_t \
  FUN( NAME const *src, T *dst, \
    size_t const count, size_t const from )

#define ZXV_COPY( NAME, T, DLL ) \
  ZXV__COPY( NAME, T, DLL, NAME##_copy )

#define ZXV__AT(            NAME, T, DLL, FUN ) DLL T* \
  FUN( NAME const *src, size_t i )

#define ZXV_AT( NAME, T, DLL ) \
  ZXV__AT( NAME, T, DLL, NAME##_at )

#define ZXV__ISEQUAL( NAME, DLL, FUN ) DLL bool \
  FUN( NAME const *src, NAME const *cmp, size_t *I )

#define ZXV_ISEQUAL( NAME, DLL ) \
  ZXV__ISEQUAL( NAME, DLL, NAME##_isEqual )

#define ZXV__CPYEQL( NAME, DLL, FUN ) DLL NAME* \
  FUN( NAME *src, NAME const *cpy )

#define ZXV_CPYEQL( NAME, DLL ) \
  ZXV__CPYEQL( NAME, DLL, NAME##_cpyEql )

#define ZXV__OPADD( NAME, DLL, FUN ) DLL NAME* \
  FUN( NAME *src, NAME const *cpy )

#define ZXV_OPADD( NAME, DLL ) \
  ZXV__OPADD( NAME, DLL, NAME##_opAdd )

#define ZXV__OPMVL( NAME, DLL, FUN ) DLL NAME* \
  FUN( NAME *src, NAME const *cpy )

#define ZXV_OPMVL( NAME, DLL ) \
  ZXV__OPMVL( NAME, DLL, NAME##_opMvl )

#define ZXV__CMP( NAME, DLL, FUN ) DLL bool \
  FUN( NAME const *src, NAME const *cmp )

#define ZXV_CMPEQ( NAME, DLL ) \
  ZXV__CMP( NAME, DLL, NAME##_cmpEQ )

#define ZXV_CMPNE( NAME, DLL ) \
  ZXV__CMP( NAME, DLL, NAME##_cmpNE )

#define ZXV__DEC( NAME, T, T2, DLL ) \
  ZXV__INITCPY(      NAME,     DLL ); \
  ZXV__KILL(         NAME,     DLL ); \
  ZXV_TMPOBJ(        NAME, T2, DLL ); \
  ZXV_SIZE(          NAME,     DLL ); \
  ZXV_MAX_SIZE(      NAME,     DLL ); \
  ZXV_RESIZE(        NAME, T,  DLL ); \
  ZXV_CAPACITY(      NAME,     DLL ); \
  ZXV_EMPTY(         NAME,     DLL ); \
  ZXV_RESERVE(       NAME,     DLL ); \
  ZXV_GROW(          NAME, T,  DLL ); \
  ZXV_SHRINK(        NAME,     DLL ); \
  ZXV_SHRINK_TO_FIT( NAME,     DLL ); \
  ZXV__ASSIGN(       NAME, T, static, \
    (*NAME##_assign) ) = NAME##_resize; \
  ZXV_APPEND(        NAME,     DLL ); \
  ZXV_PUSH(          NAME, T,  DLL ); \
  ZXV_PUSH_BACK(     NAME, T,  DLL ); \
  ZXV_POP(           NAME, T,  DLL ); \
  ZXV_POP_BACK(      NAME,     DLL ); \
  ZXV_INSERT(        NAME,     DLL ); \
  ZXV_ERASE(         NAME,     DLL ); \
  ZXV_SWAP(          NAME,     DLL ); \
  ZXV_CLEAR(         NAME,     DLL ); \
  ZXV_REVERSE(       NAME,     DLL ); \
  ZXV_COPY(          NAME, T2, DLL ); \
  ZXV_AT(            NAME, T2, DLL ); \
  ZXV_ISEQUAL(       NAME,     DLL ); \
  ZXV_CPYEQL(        NAME,     DLL ); \
  ZXV_OPADD(         NAME,     DLL ); \
  ZXV__OPMVL(        NAME,    static, \
    (*NAME##_opMvl) ) = NAME##_opAdd; \
  ZXV_CMPEQ(         NAME,     DLL ); \
  ZXV_CMPNE(         NAME,     DLL )

#define ZXV_DEC( NAME, T, DLL ) \
  ZXV__INIT(         NAME, T, DLL ); \
  ZXV__DEC(       NAME, T, T, DLL )

#define ZXV__NS_DEC( NAME, T, T2 ) \
  NAME const def; \
  ZXV___INITCPY(      NAME,,      (*_initCpy)      ); \
  ZXV___KILL(         NAME,,      (*_kill)         ); \
  ZXV__TMPOBJ(        NAME, T2,,  (*tmpobj)        ); \
  ZXV__SIZE(          NAME,,      (*size)          ); \
  ZXV__MAX_SIZE(      NAME,,      (*max_size)      ); \
  ZXV__RESIZE(        NAME, T,,   (*resize)        ); \
  ZXV__CAPACITY(      NAME,,      (*capacity)      ); \
  ZXV__EMPTY(         NAME,,      (*empty)         ); \
  ZXV__RESERVE(       NAME,,      (*reserve)       ); \
  ZXV__GROW(          NAME, T,,   (*grow)          ); \
  ZXV__SHRINK(        NAME,,      (*shrink)        ); \
  ZXV__SHRINK_TO_FIT( NAME,,      (*shrink_to_fit) ); \
  ZXV__ASSIGN(        NAME, T,,   (*assign)        ); \
  ZXV__APPEND(        NAME,,      (*append)        ); \
  ZXV__PUSH(          NAME, T,,   (*push)          ); \
  ZXV__PUSH_BACK(     NAME, T,,   (*push_back)     ); \
  ZXV__POP(           NAME, T,,   (*pop)           ); \
  ZXV__POP_BACK(      NAME,,      (*pop_back)      ); \
  ZXV__INSERT(        NAME,,      (*insert)        ); \
  ZXV__ERASE(         NAME,,      (*erase)         ); \
  ZXV__SWAP(          NAME,,      (*swap)          ); \
  ZXV__CLEAR(         NAME,,      (*clear)         ); \
  ZXV__REVERSE(       NAME,,      (*reverse)       ); \
  ZXV__COPY(          NAME, T2,,  (*copy)          ); \
  ZXV__AT(            NAME, T2,,  (*at)            ); \
  ZXV__ISEQUAL(       NAME,,      (*isEqual)       ); \
  ZXV__CPYEQL(        NAME,,      (*cpyEql)        ); \
  ZXV__OPADD(         NAME,,      (*opAdd)         ); \
  ZXV__OPMVL(         NAME,,      (*opMvl)         ); \
  ZXV__CMP(           NAME,,      (*cmpEQ)         ); \
  ZXV__CMP(           NAME,,      (*cmpNE)         )

#define ZXV_NS_DEC( NAME, T ) \
  ZXV___INIT(         NAME, T,,   (*_init)         ); \
  ZXV__NS_DEC(        NAME, T, T )

#endif
