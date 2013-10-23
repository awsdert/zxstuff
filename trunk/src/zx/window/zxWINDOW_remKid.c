#include <zx/window.h>
ZXSYS_EXP void zxWINDOW_remKid( zxWINDOW* win, zxWINDOW *kid )
{
  size_t i = 0, stop;
  if ( !win || !kid )
    return;
  stop = zxv_size.size( &win->m_kids );
  for ( ; i < stop; ++i )
  {
    if ( win->m_kids.m_data[ i ] == kid->m_wid )
    {
      zxv_size.erase( &win->m_kids, i, i );
      return;
    }
  }
}