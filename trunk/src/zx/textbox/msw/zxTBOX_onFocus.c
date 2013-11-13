#include <zx/tbox.h>
ZXSYS ZXEVENT( zxTBOX_onFocus )
{
  zxWINDOW *win = zxwin.getWindow( event->m_obj.gid );
  zxTBOX  *tbox = NULL;
#if ZXMSW
  /*TEXTMETRIC tm;*/
  HDC dc = NULL;
  event->m_stopEvent = true;
  if ( win->m_win != zxWIN_TBOX )
    return 0;
  dc = GetDC( NULL );
  if ( !dc )
    return 0;
  tbox = (zxTBOX*)win->m_wObj.obj;
  zxtbox._setCaret( tbox );
  /*
  GetTextMetrics( dc, &tm );
  ReleaseDC( NULL, dc );
  CreateCaret( win->m_wh, NULL, 1, tm.tmHeight );
  /*zxtbox._drawText( tbox, true );*/ /*
  SendMessage( win->m_wh, WM_SETTEXT, 0, (LPARAM)tbox->m_text.m_data );
  ShowCaret( win->m_wh );
  */
#else
  event->m_stopEvent = true;
#endif
  return 0;
}
