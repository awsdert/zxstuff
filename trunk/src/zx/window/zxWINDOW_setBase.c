#include <zx/window.h>
ZXSYS void zxWINDOW_setBase( zxWINDOW *win, zxWINDOW *base )
{
  if ( win && base )
    win->m_base = base->m_obj.gid;
}
