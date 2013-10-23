#include <zx/window.h>
ZXSYS_EXP bool zxWINDOW_isKnown( zxWINDOW *win )
{
  zxWINDOWS *all = zxwin.allWindows();
  size_t i = 0, stop = zx_win.size( all );
  for ( ; i < stop; ++i )
  {
    if ( win == all->m_data[ i ] )
      return true;
  }
  return false;
}