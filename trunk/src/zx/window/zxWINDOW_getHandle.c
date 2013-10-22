#include <zx/window.h>
ZXSYS_EXP zxHwnd zxWINDOW_getHandle( size_t wid )
{
  zxWINDOW *win = zxwin.getWindow(wid);
  if ( win )
    return win->m_wh;
  return NULL;
}