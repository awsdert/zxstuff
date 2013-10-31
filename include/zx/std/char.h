#pragma once
#include "_text.h"

#ifndef ZXCHAR_H
#define ZXCHAR_H
ZXC_OPEN

#define ZX_CHAR( m_txt ) m_txt

ZXV_DEC( zxCHAR, char );

ZXV_DEC_2ND( zxCHAR, char, ZXCORE );
ZXCORE size_t zxCHAR_len( char const *text );
ZXCORE void   zxCHAR__initW( zxCHAR       *dst,
                                 wide   const *text,
                                 size_t       len );

ZXNSO( c )
{
  ZXV_DEC_BODY( zxCHAR, char );
  size_t (*len)( char const *text );
  /* _initC for zxstr usage */
  void   (*_initC)( zxCHAR *dst, char const *text, size_t len );
  void   (*_initW)( zxCHAR *dst, wide const *text, size_t len );
} zxn_c;

static zxn_c const zxc =
{
  ZXV_DEF_BODY( zxCHAR, {0} ),
  zxCHAR_len,
  zxCHAR__init,
  zxCHAR__initW
};

ZXC_SHUT

#if ZXCPP

class zxChar : public zxCHAR
{
public:
  zxChar( void )
    { zxc._init( this, NULL, 0 ); }
  zxChar( char const *text, size_t len = 0 )
    { zxc._init( this, text, len ); }
  zxChar( wide const *text, size_t len = 0 )
    { zxc._initW( this, text, len ); }
  zxChar( zxCHAR const *text )
    { zxc._init( this, text->m_data, text->m_core.m_count ); }
  zxChar( zxChar const &text )
    { zxc._init( this, text.m_data, text.m_core.m_count ); }
  ~zxChar( void )
    { zxc._kill( this ); }
  size_t size( void )
    { zxc.size( this ); }
  char& at( size_t const i )
    { *zxc.at( this, i ); }
  char& operator[] ( size_t const i )
    { *zxc.at( this, i ); }
};

#endif

#endif
