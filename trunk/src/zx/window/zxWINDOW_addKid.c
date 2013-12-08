#include <zx/window.h>
ZXSYS void zxWINDOW_addKid( zxWINDOW *win, zxWINDOW *kid )
{
  if ( !win || kid )
    return;
  zxv_ui.push_back( &win->m_kids, kid->m_wid, true );
}
