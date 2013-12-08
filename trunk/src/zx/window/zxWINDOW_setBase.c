#include <zx/window.h>
ZXSYS void zxWINDOW_setBase( zxWINDOW *win, zxWINDOW *base )
{
  if ( win && base )
  {
    win->m_base = base->m_wid;
    zxv_ui.push( &base->m_kids, win->m_wid, -1, true );
  }
}
