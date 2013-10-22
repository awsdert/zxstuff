#include <zx/window.h>
ZXSYS_EXP zxWINDOW* zxWINDOW_byHandle( zxHwnd wh )
{
  zxWINDOWS *all = zxwin.allWindows();
  size_t i = 0, stop = zx_win.size( all );
  for ( ; i < stop; ++i )
  {
    if ( all->m_data[ i ]->m_wh == wh )
      return all->m_data[ i ];
  }
  return NULL;
}