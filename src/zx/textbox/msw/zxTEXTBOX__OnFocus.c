#include <zx/textbox.h>
zxEvtCBR zxTEXTBOX__OnFocus( zxWINDOW* win, zxEVENT* event )
{
#if ZXMSW
  zxTEXTBOX *tbox = NULL;
  TEXTMETRIC tm;
  HDC dc = NULL;
  if ( win->m_winType != zxWIN_TEXTBOX )
    return zxDefWinEvt;
  dc = GetDC( NULL );
  if ( !dc )
    return zxDefWinEvt;
  tbox = (zxTEXTBOX*)win;
  GetTextMetrics( dc, &tm );
  ReleaseDC( NULL, dc );
  CreateCaret( win->m_hdl, NULL, 1, tm.tmHeight );
  zx_TEXTBOX_DrawText( tbox, true );
  ShowCaret( win->m_hdl );
  return zxDefWinEvt;
#else
  return zxDefWinEvt;
#endif
}
