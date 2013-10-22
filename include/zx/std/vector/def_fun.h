#pragma once
#include "dec_fun.h"
#ifndef ZXV_DEF_FUN_H
#define ZXV_DEF_FUN_H

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
    zxv.resize( &src->m_core, setCount, (zxuc*)&setNew ); \
    src->m_data = (T*)src->m_core.m_data; \
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

#define ZXV_DEF_RESERVE( NAME, T, EXP ) \
  ZXV_RESERVE( NAME, EXP ) \
  { \
    ZXASSERT( !src ) return; \
    zxv.reserve( &src->m_core, minSize ); \
    src->m_data = (T*)src->m_core.m_data; \
  }

#define ZXV_DEF_GROW( NAME, T, EXP ) \
  ZXV_GROW( NAME, T, EXP ) \
  { \
    ZXASSERT( !src ) return; \
    zxv.grow( &src->m_core, setCount, (zxuc*)&setNew ); \
    src->m_data = (T*)src->m_core.m_data; \
  }

#define ZXV_DEF_SHRINK( NAME, T, EXP ) \
  ZXV_SHRINK( NAME, EXP ) \
  { \
    ZXASSERT( !src ) return; \
    zxv.shrink( &src->m_core, setCount ); \
    src->m_data = (T*)src->m_core.m_data; \
  }

#define ZXV_DEF_SHRINK_TO_FIT( NAME, T, EXP ) \
  ZXV_SHRINK_TO_FIT( NAME, EXP ) \
  { \
    ZXASSERT( !src ) return; \
    zxv.shrink_to_fit( &src->m_core ); \
    src->m_data = (T*)src->m_core.m_data; \
  }

#define ZXV_DEF_APPEND( NAME, T, EXP ) \
  ZXV_APPEND( NAME, EXP ) \
  { \
    ZXASSERT( !src || !cpy ) return; \
    zxv.append( &src->m_core, &cpy->m_core, pos ); \
    src->m_data = (T*)src->m_core.m_data; \
  }

#define ZXV_DEF_PUSH_BACK( NAME, T, EXP ) \
  ZXV_PUSH_BACK( NAME, EXP ) \
  { \
    bool r = false; \
    ZXASSERT( !src || !cpy ) return r; \
    r = zxv.push_back( &src->m_core, &cpy->m_core ); \
    src->m_data = (T*)src->m_core.m_data; \
    return r; \
  }

#define ZXV_DEF_POP_BACK( NAME, EXP ) \
  ZXV_POP_BACK( NAME, EXP ) \
  { \
    ZXASSERT( !src ) return; \
    zxv.pop_back( &src->m_core ); \
  }

#define ZXV_DEF_INSERT( NAME, T, EXP ) \
  ZXV_INSERT( NAME, EXP ) \
  { \
    ZXASSERT( !src || !cpy ) return; \
    zxv.insert( &src->m_core, &cpy->m_core, pos ); \
    src->m_data = (T*)src->m_core.m_data; \
  }

#define ZXV_DEF_ERASE( NAME, EXP ) \
  ZXV_ERASE( NAME, EXP ) \
  { \
    ZXASSERT( !src ) return; \
    zxv.erase( &src->m_core, first, last ); \
  }

#define ZXV_DEF_SWAP( NAME, T, EXP ) \
  ZXV_SWAP( NAME, EXP ) \
  { \
    ZXASSERT( !src | !dst ) return; \
    zxv.swap( &src->m_core, &dst->m_core ); \
    src->m_data = (T*)src->m_core.m_data; \
    dst->m_data = (T*)dst->m_core.m_data; \
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
      return src->m_data[ i ]; \
    return NULL; \
  }

#define ZXV_DEF(         NAME, T, EXP ) \
  ZXV_DEF_SIZE(          NAME,    EXP ) \
  ZXV_DEF_MAX_SIZE(      NAME,    EXP ) \
  ZXV_DEF_RESIZE(        NAME, T, EXP ) \
  ZXV_DEF_CAPACITY(      NAME,    EXP ) \
  ZXV_DEF_EMPTY(         NAME,    EXP ) \
  ZXV_DEF_RESERVE(       NAME, T, EXP ) \
  ZXV_DEF_GROW(          NAME, T, EXP ) \
  ZXV_DEF_SHRINK(        NAME, T, EXP ) \
  ZXV_DEF_SHRINK_TO_FIT( NAME, T, EXP ) \
  ZXV_DEF_APPEND(        NAME, T, EXP ) \
  ZXV_DEF_PUSH_BACK(     NAME, T, EXP ) \
  ZXV_DEF_POP_BACK(      NAME,    EXP ) \
  ZXV_DEF_INSERT(        NAME, T, EXP ) \
  ZXV_DEF_ERASE(         NAME,    EXP ) \
  ZXV_DEF_SWAP(          NAME, T, EXP ) \
  ZXV_DEF_CLEAR(         NAME,    EXP ) \
  ZXV_DEF_REVERSE(       NAME,    EXP ) \
  ZXV_DEF_COPY(          NAME, T, EXP ) \
  ZXV_DEF_AT(            NAME, T, EXP )

#endif