#include <zx/window.h>
ZXSYS_EXP void zxv_zxWINDOW__init(
  zxWINDOW* win,
  zxWINDOW* const *kids,
  size_t    count )
{
  zxVECTOR *data = zxwin.allWindows();
  zxWINDOW** ary = (zxWINDOW**)data->m_data;
  size_t i = 0, stop = data->m_count;
  if ( !win )
    win = (zxWINDOW*)mnew( sizeof( zxWINDOW ), NULL );
  if ( win->m_wid )
  {
    i = win->m_wid;
    if ( i < stop && ary[ i ] )
      return;
  }
  else
  {
    for ( ; i < stop; ++i )
    {
      if ( !ary[ i ] )
        break;
    }
  }
  if ( i >= stop )
  {
    if ( i >= SSIZE_MAX )
      return;
    zxv.grow( data, i + 1, NULL );
    ary = (zxWINDOW**)data->m_data;
  }
  win->m_wid = i;
  ary[ i ]   = win;
  if ( kids && count )
    zxv._init( &win->m_kids, sizeof( zxWINDOW* ), (zxuc*)kids, count );
}