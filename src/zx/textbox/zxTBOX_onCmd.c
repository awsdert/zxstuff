#include <zx/tbox.h>
ZXSYS_EXP ZXEVENT( zxTBOX_onCmd )
{
  zxWINDOW *win = zxwin.getWindow( event->m_obj.gid );
  zxTBOX   *tbox;
  if ( win->m_win != zxWIN_TBOX )
    return 0;
  tbox = (zxTBOX*)win->m_wObj.obj;
  return 0;
}