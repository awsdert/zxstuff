#include <zx/window.h>
ZXSYS void zxWINDOW_remKid( zxWINDOW* win, zxWINDOW *kid )
{
  if ( !win || !kid )
    return;
  zxv_size.pop( &win->m_kids, kid->m_obj.gid, 0, -1 );
}
