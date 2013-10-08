#include "window.h"
#ifndef zxTEXTBOX_H
#define zxTEXTBOX_H

ZXC_OPEN
typedef struct zxTEXTBOX_struct
{
  zxWINDOW m_win;
  zxTEXT   m_text;
  zxuint   m_pos;
#if ZXMSW
  HFONT m_font;
#endif
/* These are for Application development */
  zxEvtCBR (*onChar)( struct zxTEXTBOX_struct* tbox, zxEVENT* event );
  zxEvtCBR (*onKeyD)( struct zxTEXTBOX_struct* tbox, zxEVENT* event );
  zxEvtCBR (*onKeyP)( struct zxTEXTBOX_struct* tbox, zxEVENT* event );
  zxEvtCBR (*onKeyU)( struct zxTEXTBOX_struct* tbox, zxEVENT* event );
} zxTEXTBOX;

ZXSYS zxTEXTBOX* zxNewTEXTBOX( void );
ZXSYS bool zx_TEXTBOX_DrawText( zxTEXTBOX *tbox, bool setCaret );
ZXSYS zxEvtCBR zxTEXTBOX__OnFocus( zxWINDOW* win,  zxEVENT* event );
ZXSYS zxEvtCBR zxTEXTBOX__OnBlur(  zxWINDOW* win,  zxEVENT* event );
ZXSYS zxEvtCBR zxTEXTBOX__OnChar(  zxWINDOW* win,  zxEVENT* event );
ZXSYS zxEvtCBR zxTEXTBOX__OnKeyD(  zxWINDOW* win,  zxEVENT* event );
ZXSYS zxEvtCBR zxTEXTBOX__OnKeyP(  zxWINDOW* win,  zxEVENT* event );
ZXSYS zxEvtCBR zxTEXTBOX__OnKeyU(  zxWINDOW* win,  zxEVENT* event );

ZXC_SHUT

#endif
