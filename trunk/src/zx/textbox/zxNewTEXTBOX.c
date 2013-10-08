#include <zx/textbox.h>
ZXSYS_EXP zxTEXTBOX* zxNewTEXTBOX( void )
{
  zxTEXTBOX* tbox = (zxTEXTBOX*)malloc( sizeof( zxTEXTBOX ) );
  zxWINDOW*  win  = &tbox->m_win;
  win->m_winType = zxWIN_TEXTBOX;
  zx_InitWINDOW( win  );
  zxstr._init( &tbox->m_text, NULL, 0 );
  tbox->m_pos     = 0;
#if ZXMSW
  tbox->m_font    = NULL;
#endif
   win->m_onFocus = zxTEXTBOX__OnFocus;
   win->m_onChar  = zxTEXTBOX__OnChar;
   win->m_onKeyD  = zxTEXTBOX__OnKeyD;
   win->m_onKeyP  = zxTEXTBOX__OnKeyP;
   win->m_onKeyU  = zxTEXTBOX__OnKeyU;
  tbox->onChar    = NULL;
  tbox->onKeyD    = NULL;
  tbox->onKeyP    = NULL;
  tbox->onKeyU    = NULL;
  return tbox;
}
