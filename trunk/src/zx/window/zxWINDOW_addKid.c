#include <zx/window.h>
ZXSYS_EXP void zxWINDOW_addKid( zxWINDOW *win, zxWINDOW *kid )
{
  if ( !win || kid )
    return;
  zxv_size.push_back( &win->m_kids, kid->m_obj.gid, true );
}