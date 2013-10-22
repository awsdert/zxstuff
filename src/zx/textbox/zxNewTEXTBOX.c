#include <zx/textbox.h>
ZXSYS_EXP zxTEXTBOX* zxNewTEXTBOX( void )
{
  zxTEXTBOX *tbox = (zxTEXTBOX*)malloc( sizeof( zxTEXTBOX ) );
  zxWINDOW  *win  = tbox->m_win;
  zxEVENTS  *evts = &win->m_events;
  zxEVTPTR ptr;
  win->m_win      = zxWIN_TEXTBOX;
  zxstr._init( &tbox->m_text, NULL, 0 );
  tbox->m_pos     = 0;
#if ZXMSW
  tbox->m_font    = NULL;
#endif
  ptr.type  = zxEVT_CHAR;
  ptr.event = zxTEXTBOX_onChar;
  zxevt.addEvent( evts, ptr );
  ptr.type  = zxEVT_KEYD;
  ptr.event = zxTEXTBOX_onKeyD;
  zxevt.addEvent( evts, ptr );
  ptr.type  = zxEVT_KEYU;
  ptr.event = zxTEXTBOX_onKeyU;
  zxevt.addEvent( evts, ptr );
  ptr.type  = zxEVT_FOCUS;
  ptr.event = zxTEXTBOX_onFocus;
  zxevt.addEvent( evts, ptr );
  return tbox;
}
