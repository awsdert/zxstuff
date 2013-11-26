#include <zx/tbox.h>
ZXSYS ZXEVENT( zxTBOX_onCmd )
{
#if 0
  zxWINDOW *win = zxwin.getWindow( event->m_wid );
  zxTBOX   *tbox;
  if ( win->m_win != zxWIN_TBOX )
    return 0;
  tbox = (zxTBOX*)win->m_wObj.obj;
#endif
  return 0;
}
