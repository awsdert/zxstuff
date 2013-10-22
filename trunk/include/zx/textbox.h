#pragma once
#include "window.h"
#ifndef zxTEXTBOX_H
#define zxTEXTBOX_H

ZXC_OPEN

typedef struct zxTEXTBOX_struct
{
  zxWINDOW *m_win;
  zxTEXT    m_text;
  zxuint    m_pos;
#if ZXMSW
  HFONT     m_font;
#endif
} zxTEXTBOX;

ZXSYS zxTEXTBOX* zxTEXTBOX_opNew( zxWINDOW* win );
ZXSYS bool zxTEXTBOX__drawText( zxTEXTBOX *tbox, bool setCaret );
ZXSYS ZXEVENT( zxTEXTBOX_onChar  );
ZXSYS ZXEVENT( zxTEXTBOX_onKeyD  );
ZXSYS ZXEVENT( zxTEXTBOX_onKeyU  );
ZXSYS ZXEVENT( zxTEXTBOX_onFocus );
ZXSYS ZXEVENT( zxTEXTBOX_onBlur  );

ZXNSO( tbox )
{
  bool       (*_drawText)( zxTEXTBOX *tbox, bool setCaret );
  zxTEXTBOX* (*opNew)( zxWINDOW* win );
} zxn_tbox;

static zxn_tbox const zxtbox =
{
  zxTEXTBOX__drawText,
  zxTEXTBOX_opNew
};

ZXC_SHUT

#endif
