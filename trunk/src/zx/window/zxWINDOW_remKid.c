#include <zx/window.h>
ZXSYS void zxWINDOW_remKid( zxWINDOW* win, zxWINDOW *kid )
{
  if ( !win || !kid )
    return;
  zxv_ui.pop( &win->m_kids, kid->m_wid, 0, -1 );
}
