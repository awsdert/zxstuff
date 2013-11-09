#include <zx/window.h>
ZXSYS_EXP zxWINDOW* zxWINDOW_opNew( zxWINDOW* win )
{
  zxWINDOWS *all = zxwin.allWindows();
  size_t i = 0, stop = zx_win.size( all );
  if ( !win )
  {
    win = (zxWINDOW*)mnew( sizeof( zxWINDOW ), NULL );
    for ( ; i < stop; ++i )
    {
      if ( !all->m_data[ i ] )
        break;
    }
  }
  else
  {
    i = win->m_obj.gid;
    if ( i >= stop || ( all->m_data[ i ] && all->m_data[ i ] != win ) )
      i = stop;
  }
  if ( i >= stop )
    zx_win.grow( all, i + 1, NULL );
  *win = zxwin.def;
  win->m_obj.gid       = i;
  all->m_data[ i ] = win;
  zxevt._init( &win->m_events, NULL, 0 );
  return win;
}