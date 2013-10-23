#include <zx/tbox.h>
ZXSYS_EXP zxEvtCBR zxTBOX_onFocus( zxEVENT* event )
{
  zxWINDOW  *win  = zxwin.getWindow( event->m_wid );
  zxTBOX *tbox = NULL;
#if ZXMSW
  TEXTMETRIC tm;
  HDC dc = NULL;
  if ( win->m_win != zxWIN_TBOX )
    return zxDefWinEvt;
  dc = GetDC( NULL );
  if ( !dc )
    return zxDefWinEvt;
  tbox = (zxTBOX*)win;
  GetTextMetrics( dc, &tm );
  ReleaseDC( NULL, dc );
  CreateCaret( win->m_wh, NULL, 1, tm.tmHeight );
  zxtbox._drawText( tbox, true );
  ShowCaret( win->m_wh );
#endif
  return zxDefWinEvt;
}
