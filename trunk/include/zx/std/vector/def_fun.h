#pragma once
#ifndef ZXV_DEF
#include "dec_fun.h"

#define ZXV_DEF__INIT( NAME, T, EXP, CALL ) \
  ZXV__INIT( NAME, T, EXP, CALL ) \
  { \
    ZXASSERT( !src ) return; \
    zxv._init( &src->m_core, sizeof( T ), cpy, count, \
      (void**)&src->m_data ); \
  }

#define ZXV_DEF__INITCPY( NAME, T, EXP, CALL ) \
  ZXV__INITCPY( NAME, EXP, CALL ) \
  { \
    ZXASSERT( !src || !cpy ) return; \
    zxv._initCpy( &src->m_core, &cpy->m_core ); \
    src->m_core.m_ptr = (void**)&( src->m_data ); \
    src->m_data = (T*)src->m_core.m_data; \
  }

#define ZXV_DEF__KILL( NAME, EXP, CALL ) \
  ZXV__KILL( NAME, EXP, CALL ) \
  { \
    if ( !src ) return; \
    zxv._kill( &src->m_core ); \
  }

#define ZXV_DEF_SIZE( NAME, EXP, CALL ) \
  ZXV_SIZE( NAME, EXP, CALL ) \
  { \
    ZXASSERT( !src ) return 0; \
    return zxv.size( &src->m_core ); \
  }

#define ZXV_DEF_MAX_SIZE( NAME, EXP, CALL ) \
  ZXV_MAX_SIZE( NAME, EXP, CALL ) \
  { \
    ZXASSERT( !src ) return 0; \
    return zxv.max_size( &src->m_core ); \
  }

#define ZXV_DEF_RESIZE( NAME, T, EXP, CALL ) \
  ZXV_RESIZE( NAME, T, EXP, CALL ) \
  { \
    ZXASSERT( !src ) return; \
    zxv.resize( &src->m_core, setCount, (void*)&setNew ); \
  }

#define ZXV_DEF_CAPACITY( NAME, EXP, CALL ) \
  ZXV_CAPACITY( NAME, EXP, CALL ) \
  { \
    ZXASSERT( !src ) return 0; \
    return zxv.capacity( &src->m_core ); \
  }

#define ZXV_DEF_EMPTY( NAME, EXP, CALL ) \
  ZXV_EMPTY( NAME, EXP, CALL ) \
  { \
    ZXASSERT( !src ) return true; \
    return zxv.empty( &src->m_core ); \
  }

#define ZXV_DEF_RESERVE( NAME, EXP, CALL ) \
  ZXV_RESERVE( NAME, EXP, CALL ) \
  { \
    ZXASSERT( !src ) return; \
    zxv.reserve( &src->m_core, minSize ); \
  }

#define ZXV_DEF_GROW( NAME, T, EXP, CALL ) \
  ZXV_GROW( NAME, T, EXP, CALL ) \
  { \
    ZXASSERT( !src ) return; \
    zxv.grow( &src->m_core, setCount, (void*)&setNew ); \
  }

#define ZXV_DEF_SHRINK( NAME, EXP, CALL ) \
  ZXV_SHRINK( NAME, EXP, CALL ) \
  { \
    ZXASSERT( !src ) return; \
    zxv.shrink( &src->m_core, setCount ); \
  }

#define ZXV_DEF_SHRINK_TO_FIT( NAME, EXP, CALL ) \
  ZXV_SHRINK_TO_FIT( NAME, EXP, CALL ) \
  { \
    ZXASSERT( !src ) return; \
    zxv.shrink_to_fit( &src->m_core ); \
  }

#define ZXV_DEF_APPEND( NAME, EXP, CALL ) \
  ZXV_APPEND( NAME, EXP, CALL ) \
  { \
    ZXASSERT( !src || !cpy ) return; \
    zxv.append( &src->m_core, &cpy->m_core, pos ); \
  }

#define ZXV_DEF_PUSH( NAME, T, EXP, CALL ) \
  ZXV_PUSH( NAME, T, EXP, CALL ) \
  { \
    ZXASSERT( !src ) return false; \
    return zxv.push( &src->m_core, (void*)&cpy, pos, unique ); \
  }

#define ZXV_DEF_PUSH_BACK( NAME, T, EXP, CALL ) \
  ZXV_PUSH_BACK( NAME, T, EXP, CALL ) \
  { \
    ZXASSERT( !src ) return false; \
    return zxv.push_back( &src->m_core, (void*)&cpy, unique ); \
  }

#define ZXV_DEF_POP( NAME, T, EXP, CALL ) \
    ZXV_POP( NAME, T, EXP, CALL ) \
    { \
      ZXASSERT( !src ) return; \
      zxv.pop( &src->m_core, (void*)&cmp, first, last ); \
    }

#define ZXV_DEF_POP_BACK( NAME, EXP, CALL ) \
  ZXV_POP_BACK( NAME, EXP, CALL ) \
  { \
    ZXASSERT( !src ) return; \
    zxv.pop_back( &src->m_core ); \
  }

#define ZXV_DEF_INSERT( NAME, EXP, CALL ) \
  ZXV_INSERT( NAME, EXP, CALL ) \
  { \
    ZXASSERT( !src || !cpy ) return; \
    zxv.insert( &src->m_core, &cpy->m_core, pos ); \
  }

#define ZXV_DEF_ERASE( NAME, EXP, CALL ) \
  ZXV_ERASE( NAME, EXP, CALL ) \
  { \
    ZXASSERT( !src ) return; \
    zxv.erase( &src->m_core, first, last ); \
  }

#define ZXV_DEF_SWAP( NAME, EXP, CALL ) \
  ZXV_SWAP( NAME, EXP, CALL ) \
  { \
    ZXASSERT( !src | !dst ) return; \
    zxv.swap( &src->m_core, &dst->m_core ); \
  }

#define ZXV_DEF_CLEAR( NAME, EXP, CALL ) \
  ZXV_CLEAR( NAME, EXP, CALL ) \
  { \
    ZXASSERT( !src ) return; \
    zxv.clear( &src->m_core ); \
  }

#define ZXV_DEF_REVERSE( NAME, EXP, CALL ) \
  ZXV_REVERSE( NAME, EXP, CALL ) \
  { \
    ZXASSERT( !src ) return; \
    zxv.reverse( &src->m_core ); \
  }

#define ZXV_DEF_COPY( NAME, T, EXP, CALL ) \
  ZXV_COPY( NAME, T, EXP, CALL ) \
  { \
    ZXASSERT( !src || !dst || !count ) return 0; \
    return zxv.copy( &src->m_core, dst, count, from ); \
  }

#define ZXV_DEF_AT( NAME, T, EXP, CALL ) \
  ZXV_AT( NAME, T, EXP, CALL ) \
  { \
    ZXASSERT( !src ) return NULL; \
    if ( zxv.at( &src->m_core, i ) ) \
      return &src->m_data[ i ]; \
    return NULL; \
  }

#define ZXV_DEF_ISEQUAL( NAME, EXP, CALL ) \
  ZXV_ISEQUAL( NAME, EXP, CALL ) \
  { \
    if ( src == cmp ) return true; \
    ZXASSERT( !src || !cmp ) return false; \
    return zxv.isEqual( &src->m_core, &cmp->m_core, I ); \
  }

#define ZXV_DEF_OPEQL( NAME, EXP, CALL ) \
  ZXV_OPEQL( NAME, EXP, CALL ) \
  { \
    ZXASSERT( !src | !cpy ) return src; \
    zxv.opEql( &src->m_core, &cpy->m_core ); \
    return src; \
  }

#define ZXV_DEF_OPADD( NAME, T, EXP, CALL ) \
  ZXV_OPADD( NAME, EXP, CALL ) \
  { \
    ZXASSERT( !src || !cpy ) return src; \
    zxv.opAdd( &src->m_core, &cpy->m_core ); \
    src->m_data = (T*)src->m_core.m_data; \
    return src; \
  }

#define ZXV_DEF_CMPEQ( NAME, EXP, CALL ) \
  ZXV_CMPEQ( NAME, EXP, CALL ) \
  { \
    if ( src == cmp ) return true; \
    ZXASSERT( !src || !cmp ) return false; \
    return zxv.isEqual( &src->m_core, &cmp->m_core, NULL ); \
  }

#define ZXV_DEF_CMPNE( NAME, EXP, CALL ) \
  ZXV_CMPNE( NAME, EXP, CALL ) \
  { \
    if ( src == cmp ) return false; \
    ZXASSERT( !src || !cmp ) return true; \
    return !zxv.isEqual( &src->m_core, &cmp->m_core, NULL ); \
  }

#define ZXV_DEF(         NAME, T, EXP, CALL ) \
  ZXV_DEF__INIT(         NAME, T, EXP, CALL ) \
  ZXV_DEF__INITCPY(      NAME, T, EXP, CALL ) \
  ZXV_DEF__KILL(         NAME,    EXP, CALL ) \
  ZXV_DEF_SIZE(          NAME,    EXP, CALL ) \
  ZXV_DEF_MAX_SIZE(      NAME,    EXP, CALL ) \
  ZXV_DEF_RESIZE(        NAME, T, EXP, CALL ) \
  ZXV_DEF_CAPACITY(      NAME,    EXP, CALL ) \
  ZXV_DEF_EMPTY(         NAME,    EXP, CALL ) \
  ZXV_DEF_RESERVE(       NAME,    EXP, CALL ) \
  ZXV_DEF_GROW(          NAME, T, EXP, CALL ) \
  ZXV_DEF_SHRINK(        NAME,    EXP, CALL ) \
  ZXV_DEF_SHRINK_TO_FIT( NAME,    EXP, CALL ) \
  ZXV_DEF_APPEND(        NAME,    EXP, CALL ) \
  ZXV_DEF_PUSH(          NAME, T, EXP, CALL ) \
  ZXV_DEF_PUSH_BACK(     NAME, T, EXP, CALL ) \
  ZXV_DEF_POP(           NAME, T, EXP, CALL ) \
  ZXV_DEF_POP_BACK(      NAME,    EXP, CALL ) \
  ZXV_DEF_INSERT(        NAME,    EXP, CALL ) \
  ZXV_DEF_ERASE(         NAME,    EXP, CALL ) \
  ZXV_DEF_SWAP(          NAME,    EXP, CALL ) \
  ZXV_DEF_CLEAR(         NAME,    EXP, CALL ) \
  ZXV_DEF_REVERSE(       NAME,    EXP, CALL ) \
  ZXV_DEF_COPY(          NAME, T, EXP, CALL ) \
  ZXV_DEF_AT(            NAME, T, EXP, CALL ) \
  ZXV_DEF_ISEQUAL(       NAME,    EXP, CALL ) \
  ZXV_DEF_OPEQL(         NAME,    EXP, CALL ) \
  ZXV_DEF_OPADD(         NAME, T, EXP, CALL ) \
  ZXV_DEF_CMPEQ(         NAME,    EXP, CALL ) \
  ZXV_DEF_CMPNE(         NAME,    EXP, CALL )

#define ZXV_NS_DEF( NAME ) \
  NAME##__init, {0}, \
  NAME##__initCpy, \
  NAME##__kill, \
  NAME##_size, \
  NAME##_max_size, \
  NAME##_resize, \
  NAME##_capacity, \
  NAME##_empty, \
  NAME##_reserve, \
  NAME##_grow, \
  NAME##_shrink, \
  NAME##_shrink_to_fit, \
  NAME##_resize, \
  NAME##_append, \
  NAME##_push, \
  NAME##_push_back, \
  NAME##_pop, \
  NAME##_pop_back, \
  NAME##_insert, \
  NAME##_erase, \
  NAME##_swap, \
  NAME##_clear, \
  NAME##_reverse, \
  NAME##_copy, \
  NAME##_at, \
  NAME##_isEqual, \
  NAME##_opEql, \
  NAME##_opAdd, \
  NAME##_opAdd, \
  NAME##_cmpEQ, \
  NAME##_cmpNE

#endif
