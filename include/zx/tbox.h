#pragma once
#ifndef ZX_TBOX_H
#define ZX_TBOX_H
#include "window.h"

ZXC_OPEN

typedef ZXSOBJ( zxTBOX )
{
  zxWINDOW *m_win;
  zxui      m_fc, m_lc;
} zxTBOX;

ZXNSO( tbox )
{
  zxTBOX const def;
  bool    (*_setText)(  zxTBOX *tbox );
  bool    (*_drawText)( zxTBOX *tbox, bool setCaret );
  bool    (*_setCaret)( zxTBOX *tbox );
  zxTBOX* (*opNew)( zxWINDOW* win    );
  opDelVoid opDel;
} zxn_tbox;

extern zxn_tbox const zxtbox;

ZXC_SHUT

#if ZXCPP

class ZXSYS zxTbox : public zxWindow
{
private:
  void _init( zxWINDOW* base, size_t *kids, size_t count )
  {
    zxtbox.opNew( this );
    m_win = zxWIN_TBOX;
    zxwin.setBase( this, base );
    zxv_size._init( &m_kids, kids, count );
  }
public:
  zxTbox( void )
    { _init( NULL, NULL, 0 ); }
  zxTbox( zxWINDOW* base )
    { _init( base, NULL, 0 ); }
  zxTbox( zxWINDOW* base, size_t* kids, size_t count )
    { _init( base, kids, count ); }
};

#endif

#endif
