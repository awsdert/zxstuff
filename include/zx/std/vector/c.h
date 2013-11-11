#include "../lib.h"
#include "../math.h"
#include "def_fun.h"

#pragma once
#ifndef ZXV_C_H
#define ZXV_C_H

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
  size_t         Tsize,
  void     const *cpy,
  size_t         count );
ZXV__DEC( zxVECTOR, void*, void, ZXCORE );

ZXNSO( v )
{
  void (*_init)(
    zxVECTOR   *src, size_t Tsize,
    void const *cpy, size_t count );
  ZXV__NS_DEC( zxVECTOR, void*, void );
} zxn_v;

static const zxn_v zxv = { ZXV_NS_DEF( zxVECTOR, {0} ) };

ZXC_SHUT

#endif
