#include <zx/tbox.h>
ZXSYS ZXEVENT( zxTBOX_onFocus )
{
  zxWINDOW *win = zxwin.getWindow( event->m_wid );
  zxTBOX  *tbox = NULL;
#if ZXMSW
  if ( !win || win->m_win != zxWIN_TBOX )
    return 0;
  tbox = (zxTBOX*)win->m_wObj.obj;
  zxtbox._drawText( tbox, true );
  event->m_stopEvent = true;
#endif
  return 0;
}
