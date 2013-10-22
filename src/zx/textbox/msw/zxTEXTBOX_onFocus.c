#include <zx/textbox.h>
ZXSYS_EXP zxEvtCBR zxTEXTBOX_onFocus( zxEVENT* event )
{
  zxWINDOW  *win  = zxwin.getWindow( event->m_wid );
  zxTEXTBOX *tbox = NULL;
#if ZXMSW
  TEXTMETRIC tm;
  HDC dc = NULL;
  if ( win->m_win != zxWIN_TEXTBOX )
    return zxDefWinEvt;
  dc = GetDC( NULL );
  if ( !dc )
    return zxDefWinEvt;
  tbox = (zxTEXTBOX*)win;
  GetTextMetrics( dc, &tm );
  ReleaseDC( NULL, dc );
  CreateCaret( win->m_wh, NULL, 1, tm.tmHeight );
  zxtbox._drawText( tbox, true );
  ShowCaret( win->m_wh );
#endif
  return zxDefWinEvt;
}
