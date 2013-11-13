#include <zx/window.h>
ZXSYS zxHwnd zxWINDOW_getHandle( size_t gid )
{
  zxWINDOW *win = zxwin.getWindow( gid );
  if ( win )
    return win->m_wh;
  return NULL;
}
