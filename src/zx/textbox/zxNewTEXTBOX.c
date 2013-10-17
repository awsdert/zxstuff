#include <zx/textbox.h>
ZXSYS_EXP zxTEXTBOX* zxNewTEXTBOX( void )
{
  zxTEXTBOX *tbox = (zxTEXTBOX*)malloc( sizeof( zxTEXTBOX ) );
  zxWINDOW  *win  = &tbox->m_win;
  zxEVENTS  *evts = &win->m_events;
  zxEVTPTR ptr;
  win->m_win      = zxWIN_TEXTBOX;
  zxwin._init( win, NULL, 0 );
  zxstr._init( &tbox->m_text, NULL, 0 );
  tbox->m_pos     = 0;
#if ZXMSW
  tbox->m_font    = NULL;
#endif
  ptr.type  = zxEVT_CHAR;
  ptr.event = zxv_zxTEXTBOX_onChar;
  zxAddEvent( evts, ptr );
  ptr.type  = zxEVT_KEYD;
  ptr.event = zxv_zxTEXTBOX_onKeyD;
  zxAddEvent( evts, ptr );
  ptr.type  = zxEVT_KEYU;
  ptr.event = zxv_zxTEXTBOX_onKeyU;
  zxAddEvent( evts, ptr );
  ptr.type  = zxEVT_FOCUS;
  ptr.event = zxv_zxTEXTBOX_onFocus;
  zxAddEvent( evts, ptr );
  return tbox;
}
