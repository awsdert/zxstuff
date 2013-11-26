#pragma once
#ifndef ZXV_C_H
#define ZXV_C_H
#include "def_fun.h"

ZXC_OPEN

#define ZXVECTOR( DATA, PTR, ISFIXED, T, COUNT ) \
  { DATA, PTR, ISFIXED, sizeof( T ), \
  COUNT, COUNT, sizeof( T ) * COUNT, sizeof( T ) * COUNT }

typedef ZXSOBJ( zxVECTOR )
{
  void*   m_data;
  void**  m_ptr;
  bool    m_isFixed;
  size_t  m_Tsize;
  size_t  m_count, m_fullCount;
  size_t  m_size,  m_fullSize;
} zxVECTOR;

ZXCORE void   zxVECTOR__init(
  zxVECTOR       *src,
  size_t          Tsize,
  void     const *cpy,
  size_t          count,
  void          **ptr );
ZXV__DEC( zxVECTOR, void*, void, ZXCORE, ZXCORE_CALL );

ZXNSO( v )
{
  void (*_init)(
    zxVECTOR   *src, size_t Tsize,
    void const *cpy, size_t count, void **ptr );
  ZXV__NS_DEC( zxVECTOR, void*, void, ZXCORE_CALL );
} zxn_v;

extern zxn_v const zxv;

#define ZX__PRAG( MSG ) _Pragma( #MSG )
#define ZX_PRAG( MSG ) ZX__PRAG( message ZXMSG( MSG ) )
#define ZXPRAG( MSG ) ZX_PRAG( MSG )
/*
ZXPRAG( ZXV__INIT( zxVECTOR, void, ZXCORE, ZXCORE_CALL ) )
/* */

ZXC_SHUT

#endif
