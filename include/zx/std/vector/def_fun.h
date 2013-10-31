#pragma once
#include "dec_fun.h"
#ifndef ZXV_DEF_FUN_H
#define ZXV_DEF_FUN_H

#define ZXV_DEF__INIT( NAME, T, EXP ) \
  ZXV__INIT( NAME, T, EXP ) \
  { \
    ZXASSERT( !src ) return; \
    zxv._init( &src->m_core, sizeof( T ), cpy, count ); \
    src->m_core.m_ptr = (void**)&( src->m_data ); \
    src->m_data = (T*)src->m_core.m_data; \
  }

#define ZXV_DEF__INITCPY( NAME, T, EXP ) \
  ZXV__INITCPY( NAME, EXP ) \
  { \
    ZXASSERT( !src || !cpy ) return; \
    zxv._initCpy( &src->m_core, &cpy->m_core ); \
    src->m_core.m_ptr = (void**)&( src->m_data ); \
    src->m_data = (T*)src->m_core.m_data; \
  }

#define ZXV_DEF__KILL( NAME, EXP ) \
  ZXV__KILL( NAME, EXP ) \
  { \
    if ( !src ) return; \
    zxv._kill( &src->m_core ); \
  }

#define ZXV_DEF_SIZE( NAME, EXP ) \
  ZXV_SIZE( NAME, EXP ) \
  { \
    ZXASSERT( !src ) return 0; \
    return zxv.size( &src->m_core ); \
  }

#define ZXV_DEF_MAX_SIZE( NAME, EXP ) \
  ZXV_MAX_SIZE( NAME, EXP ) \
  { \
    ZXASSERT( !src ) return 0; \
    return zxv.max_size( &src->m_core ); \
  }

#define ZXV_DEF_RESIZE( NAME, T, EXP ) \
  ZXV_RESIZE( NAME, T, EXP ) \
  { \
    ZXASSERT( !src ) return; \
    zxv.resize( &src->m_core, setCount, (void*)&setNew ); \
  }

#define ZXV_DEF_CAPACITY( NAME, EXP ) \
  ZXV_CAPACITY( NAME, EXP ) \
  { \
    ZXASSERT( !src ) return 0; \
    return zxv.capacity( &src->m_core ); \
  }

#define ZXV_DEF_EMPTY( NAME, EXP ) \
  ZXV_EMPTY( NAME, EXP ) \
  { \
    ZXASSERT( !src ) return true; \
    return zxv.empty( &src->m_core ); \
  }

#define ZXV_DEF_RESERVE( NAME, EXP ) \
  ZXV_RESERVE( NAME, EXP ) \
  { \
    ZXASSERT( !src ) return; \
    zxv.reserve( &src->m_core, minSize ); \
  }

#define ZXV_DEF_GROW( NAME, T, EXP ) \
  ZXV_GROW( NAME, T, EXP ) \
  { \
    ZXASSERT( !src ) return; \
    zxv.grow( &src->m_core, setCount, (void*)&setNew ); \
  }

#define ZXV_DEF_SHRINK( NAME, EXP ) \
  ZXV_SHRINK( NAME, EXP ) \
  { \
    ZXASSERT( !src ) return; \
    zxv.shrink( &src->m_core, setCount ); \
  }

#define ZXV_DEF_SHRINK_TO_FIT( NAME, EXP ) \
  ZXV_SHRINK_TO_FIT( NAME, EXP ) \
  { \
    ZXASSERT( !src ) return; \
    zxv.shrink_to_fit( &src->m_core ); \
  }

#define ZXV_DEF_APPEND( NAME, EXP ) \
  ZXV_APPEND( NAME, EXP ) \
  { \
    ZXASSERT( !src || !cpy ) return; \
    zxv.append( &src->m_core, &cpy->m_core, pos ); \
  }

#define ZXV_DEF_PUSH_BACK( NAME, EXP ) \
  ZXV_PUSH_BACK( NAME, EXP ) \
  { \
    bool r = false; \
    ZXASSERT( !src || !cpy ) return r; \
    r = zxv.push_back( &src->m_core, &cpy->m_core ); \
    return r; \
  }

#define ZXV_DEF_POP_BACK( NAME, EXP ) \
  ZXV_POP_BACK( NAME, EXP ) \
  { \
    ZXASSERT( !src ) return; \
    zxv.pop_back( &src->m_core ); \
  }

#define ZXV_DEF_INSERT( NAME, EXP ) \
  ZXV_INSERT( NAME, EXP ) \
  { \
    ZXASSERT( !src || !cpy ) return; \
    zxv.insert( &src->m_core, &cpy->m_core, pos ); \
  }

#define ZXV_DEF_ERASE( NAME, EXP ) \
  ZXV_ERASE( NAME, EXP ) \
  { \
    ZXASSERT( !src ) return; \
    zxv.erase( &src->m_core, first, last ); \
  }

#define ZXV_DEF_SWAP( NAME, EXP ) \
  ZXV_SWAP( NAME, EXP ) \
  { \
    ZXASSERT( !src | !dst ) return; \
    zxv.swap( &src->m_core, &dst->m_core ); \
  }

#define ZXV_DEF_CLEAR( NAME, EXP ) \
  ZXV_CLEAR( NAME, EXP ) \
  { \
    ZXASSERT( !src ) return; \
    zxv.clear( &src->m_core ); \
  }

#define ZXV_DEF_REVERSE( NAME, EXP ) \
  ZXV_REVERSE( NAME, EXP ) \
  { \
    ZXASSERT( !src ) return; \
    zxv.reverse( &src->m_core ); \
  }

#define ZXV_DEF_COPY( NAME, T, EXP ) \
  ZXV_COPY( NAME, T, EXP ) \
  { \
    ZXASSERT( !src || !dst || !count ) return 0; \
    return zxv.copy( &src->m_core, dst, count, from ); \
  }

#define ZXV_DEF_AT( NAME, T, EXP ) \
  ZXV_AT( NAME, T, EXP ) \
  { \
    ZXASSERT( !src ) return NULL; \
    if ( zxv.at( &src->m_core, i ) ) \
      return &src->m_data[ i ]; \
    return NULL; \
  }

#define ZXV_DEF_ISEQUAL( NAME, EXP ) \
  ZXV_ISEQUAL( NAME, EXP ) \
  { \
    if ( src == cmp ) return true; \
    ZXASSERT( !src || !cmp ) return false; \
    return zxv.isEqual( &src->m_core, &cmp->m_core, I ); \
  }

#define ZXV_DEF_CPYEQL( NAME, EXP ) \
  ZXV_CPYEQL( NAME, EXP ) \
  { \
    ZXASSERT( !src | !cpy ) return src; \
    zxv.cpyEql( &src->m_core, &cpy->m_core ); \
    return src; \
  }

#define ZXV_DEF_OPADD( NAME, T, EXP ) \
  ZXV_OPADD( NAME, EXP ) \
  { \
    ZXASSERT( !src || !cpy ) return src; \
    zxv.opAdd( &src->m_core, &cpy->m_core ); \
    src->m_data = (T*)src->m_core.m_data; \
    return src; \
  }

#define ZXV_DEF_CMPEQ( NAME, EXP ) \
  ZXV_CMPEQ( NAME, EXP ) \
  { \
    if ( src == cmp ) return true; \
    ZXASSERT( !src || !cmp ) return false; \
    return zxv.isEqual( &src->m_core, &cmp->m_core, NULL ); \
  }

#define ZXV_DEF_CMPNE( NAME, EXP ) \
  ZXV_CMPNE( NAME, EXP ) \
  { \
    if ( src == cmp ) return false; \
    ZXASSERT( !src || !cmp ) return true; \
    return !zxv.isEqual( &src->m_core, &cmp->m_core, NULL ); \
  }

#define ZXV_DEF(         NAME, T, EXP ) \
  ZXV_DEF__INIT(         NAME, T, EXP ) \
  ZXV_DEF__INITCPY(      NAME, T, EXP ) \
  ZXV_DEF__KILL(         NAME,    EXP ) \
  ZXV_DEF_SIZE(          NAME,    EXP ) \
  ZXV_DEF_MAX_SIZE(      NAME,    EXP ) \
  ZXV_DEF_RESIZE(        NAME, T, EXP ) \
  ZXV_DEF_CAPACITY(      NAME,    EXP ) \
  ZXV_DEF_EMPTY(         NAME,    EXP ) \
  ZXV_DEF_RESERVE(       NAME,    EXP ) \
  ZXV_DEF_GROW(          NAME, T, EXP ) \
  ZXV_DEF_SHRINK(        NAME,    EXP ) \
  ZXV_DEF_SHRINK_TO_FIT( NAME,    EXP ) \
  ZXV_DEF_APPEND(        NAME,    EXP ) \
  ZXV_DEF_PUSH_BACK(     NAME,    EXP ) \
  ZXV_DEF_POP_BACK(      NAME,    EXP ) \
  ZXV_DEF_INSERT(        NAME,    EXP ) \
  ZXV_DEF_ERASE(         NAME,    EXP ) \
  ZXV_DEF_SWAP(          NAME,    EXP ) \
  ZXV_DEF_CLEAR(         NAME,    EXP ) \
  ZXV_DEF_REVERSE(       NAME,    EXP ) \
  ZXV_DEF_COPY(          NAME, T, EXP ) \
  ZXV_DEF_AT(            NAME, T, EXP ) \
  ZXV_DEF_ISEQUAL(       NAME,    EXP ) \
  ZXV_DEF_CPYEQL(        NAME,    EXP ) \
  ZXV_DEF_OPADD(         NAME, T, EXP ) \
  ZXV_DEF_CMPEQ(         NAME,    EXP ) \
  ZXV_DEF_CMPNE(         NAME,    EXP )

#endif