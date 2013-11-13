#include <zx/window.h>
ZXSYS zxWINDOW* zxWINDOW_getKid( zxWINDOW *win, size_t i )
{
  if ( !win || !zxv_size.at( &win->m_kids, i ) )
    return NULL;
  return zxwin.getWindow( win->m_kids.m_data[ i ] );
}
ZXSYS zxWINDOW* zxWINDOW_getNext( zxWINDOW *win, bool nextKid )
{
  zxWINDOW *base;
  zxvSIZE *kids;
  size_t i = 0, stop;
  ZXASSERT( !win ) return zxwin.getWindow(0);
  kids = &win->m_kids;
  stop = zxv_size.size( kids );
  if ( !nextKid || !stop )
  {
    base = zxwin.getWindow( win->m_base );
    if ( !base )
      return win;
    kids = &base->m_kids;
    stop = zxv_size.size( kids );
  }
  else
    return zxwin.getWindow( kids->m_data[ 0 ] );
  for ( ; i < stop; ++i )
  {
    if ( kids->m_data[ i ] != win->m_obj.gid )
      return zxwin.getWindow( kids->m_data[ i ] );
  }
  return zxwin.getNext( base, false );
}
ZXSYS zxWINDOW* zxWINDOW_getPrev( zxWINDOW *win )
{
  zxWINDOW *base;
  zxvSIZE *kids;
  size_t i, stop;
  ZXASSERT( !win ) return zxwin.getRootWindow();
  base = zxwin.getWindow( win->m_base );
  if ( !base )
    return win;
  kids = &base->m_kids;
  stop = zxv_size.size( kids );
  for ( i = stop - 1; i < stop; --i, --stop )
  {
    if ( kids->m_data[ i ] == win->m_obj.gid )
      break;
  }
  if ( i > 0 )
    return zxwin.getWindow( kids->m_data[ i - 1 ] );
  return base;
}
