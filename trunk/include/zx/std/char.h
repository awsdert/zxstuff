#pragma once
#ifndef ZXC_H
#define ZXC_H
#include "_text.h"

ZXC_OPEN

#define ZX_CHAR( m_txt ) m_txt

ZXV_OBJ( zxCHAR, char );

ZXV_DEC( zxCHAR, char, ZXCORE, ZXCORE_CALL );
ZXCORE size_t ZXCORE_CALL zxCHAR_len( char const *text );
ZXV___INIT( zxCHAR, wide, ZXCORE, ZXCORE_CALL zxCHAR__initW );

ZXNSO( c )
{
  ZXV_NS_DEC( zxCHAR, char, ZXCORE_CALL );
  size_t (*len)( char const *text );
  /* _initC for zxstr usage */
  ZXV___INIT( zxCHAR, char,, (ZXCORE_CALL *_initC) );
  ZXV___INIT( zxCHAR, wide,, (ZXCORE_CALL *_initw) );
} zxn_c;

static zxn_c const zxc =
{
  ZXV_NS_DEF( zxCHAR ),
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
