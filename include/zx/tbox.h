#pragma once
#include "window.h"
#ifndef zxTBOX_H
#define zxTBOX_H

ZXC_OPEN

typedef ZXSOBJ( zxTBOX )
{
  zxWINDOW *m_win;
  zxTEXT    m_text;
  zxuint    m_pos;
#if ZXMSW
  HFONT     m_font;
#endif
} zxTBOX;

ZXSYS zxTBOX*  zxTBOX_opNew( zxWINDOW* win    );
ZXSYS void     zxTBOX_opDel( void*     winObj );
ZXSYS bool     zxTBOX__drawText( zxTBOX *tbox, bool setCaret );

ZXSYS ZXEVENT( zxTBOX_onInit  );
ZXSYS ZXEVENT( zxTBOX_onKill  );
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
  zxTBOX* (*opNew)( zxWINDOW* win    );
  opDelVoid opDel;
} zxn_tbox;

static zxn_tbox const zxtbox =
{
  {
    NULL,
    zxTBOX_onInit,
    zxTBOX_onKill,
    zxTBOX_onChar,
    zxTBOX_onKeyD,
    zxTBOX_onKeyU,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    zxTBOX_onFocus,
    zxTBOX_onBlur,
    NULL
  }, {0},
  zxTBOX__drawText,
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
    m_win = zxWIN_CPP_TBOX;
    zxwin.setBase( this, base );
    zxv_size._init( &m_kids, kids, count );
  }
public:
  zxTbox( void )
  {
  }
}

#endif

#endif
