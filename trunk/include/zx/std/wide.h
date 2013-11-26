#pragma once
#ifndef ZXW_H
#define ZXW_H
#include "_text.h"

ZXC_OPEN

#define ZX_WIDE( m_txt ) L##m_txt

ZXV_OBJ( zxWIDE, wide );
ZXV_DEC( zxWIDE, wide, ZXCORE, ZXCORE_CALL );

ZXCORE size_t ZXCORE_CALL zxWIDE_len(    wide const *text );
ZXCORE void   ZXCORE_CALL zxWIDE__initC(
  zxWIDE       *dst,
  char   const *text,
  size_t       len );

ZXNSO( w )
{
  ZXV_NS_DEC( zxWIDE, wide, ZXCORE_CALL );
  size_t (ZXCORE_CALL *len)( wide const *text );
  /* _initW for zxstr usage */
  void   (ZXCORE_CALL *_initC)( zxWIDE *dst, char const *text, size_t len );
  void   (ZXCORE_CALL *_initW)( zxWIDE *dst, wide const *text, size_t len );
} zxn_w;

static zxn_w const zxw =
{
  ZXV_NS_DEF( zxWIDE ),
  zxWIDE_len,
  zxWIDE__initC,
  zxWIDE__init
};

ZXC_SHUT

#if ZXCPP

class zxWide : public zxWIDE
{
public:
  zxWide( void )
    { zxw._init( this, NULL, 0 ); }
  zxWide( char const *text, size_t len = 0 )
    { zxw._initC( this, text, len ); }
  zxWide( wide const *text, size_t len = 0 )
    { zxw._init( this, text, len ); }
  zxWide( zxWIDE const *text )
    { zxw._init( this, text->m_data, text->m_core.m_count ); }
  zxWide( zxWide const &text )
    { zxw._init( this, text.m_data, text.m_core.m_count ); }
  ~zxWide( void )
    { zxw._kill( this ); }
  size_t size( void )
    { zxw.size( this ); }
  wide& at( size_t const i )
    { *zxw.at( this, i ); }
  wide& operator[] ( size_t const i )
    { *zxw.at( this, i ); }
};

#endif

#endif
