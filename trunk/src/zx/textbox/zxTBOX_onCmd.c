#include <zx/tbox.h>
ZXSYS_EXP ZXEVENT( zxTBOX_onCmd )
{
#if ZXMSW
  zxWINDOW *win = zxwin.getWindow( event->m_wid );
  zxTBOX   *tbox;
  if ( win->m_win != zxWIN_TBOX )
    return zxDefWinEvt;
  tbox = (zxTBOX*)win->m_winObj;
#endif
  return zxDefWinEvt;
}