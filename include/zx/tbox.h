#pragma once
#include "window.h"
#ifndef zxTBOX_H
#define zxTBOX_H

ZXC_OPEN

typedef ZXSOBJ( zxTBOX )
{
  zxWINDOW *m_win;
  zxui      m_pos;
#if ZXMSW
  DWORD     m_fc, m_lc;  
  HFONT     m_font;
#endif
} zxTBOX;

ZXSYS zxTBOX*  zxTBOX_opNew( zxWINDOW* win    );
ZXSYS void     zxTBOX_opDel( void*     winObj, size_t type );
ZXSYS bool     zxTBOX__drawText( zxTBOX *tbox, bool setCaret );
ZXSYS bool     zxTBOX__setCaret( zxTBOX *tbox );

ZXSYS ZXEVENT( zxTBOX_onInit  );
ZXSYS ZXEVENT( zxTBOX_onKill  );
ZXSYS ZXEVENT( zxTBOX_onCmd   );
ZXSYS ZXEVENT( zxTBOX_onChar  );
ZXSYS ZXEVENT( zxTBOX_onKeyD  );
ZXSYS ZXEVENT( zxTBOX_onKeyU  );
ZXSYS ZXEVENT( zxTBOX_onFocus );
ZXSYS ZXEVENT( zxTBOX_onBlur  );

ZXNSO( tbox )
{
  zxEvtPtr const events[ zxEVT_COUNT ];
  zxTBOX   const def;
  bool    (*_drawText)( zxTBOX *tbox, bool setCaret );
  bool    (*_setCaret)( zxTBOX *tbox );
  zxTBOX* (*opNew)( zxWINDOW* win    );
  opDelVoid opDel;
} zxn_tbox;

static zxn_tbox const zxtbox =
{
  {
    NULL,
    zxTBOX_onInit,
    zxTBOX_onKill,
    zxTBOX_onCmd,
    zxTBOX_onChar,
    zxTBOX_onKeyD,
    zxTBOX_onKeyU,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    zxTBOX_onFocus,
    zxTBOX_onBlur,
    NULL
  }, {0},
  zxTBOX__drawText,
  zxTBOX__setCaret,
  zxTBOX_opNew,
  zxTBOX_opDel
};

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
