#include "zxwin.h"
zxWINDOW* zxWINDOW_getKid( zxWINDOW *win, zxui i )
{
  if ( !win || !zxv_ui.at( &win->m_kids, i ) )
    return NULL;
  return zxwin.getWindow( win->m_kids.m_data[ i ] );
}
zxWINDOW* zxWINDOW_getNext( zxWINDOW *win, bool nextKid )
{
  zxWINDOW *base;
  zxvUI *kids;
  zxui i = 0, stop;
  ZXASSERT( !win ) return zxwin.getWindow(0);
  kids = &win->m_kids;
  stop = zxv_ui.size( kids );
  if ( !nextKid || !stop )
  {
    base = zxwin.getWindow( win->m_base );
    if ( !base )
      return win;
    kids = &base->m_kids;
    stop = zxv_ui.size( kids );
  }
  else
    return zxwin.getWindow( kids->m_data[ 0 ] );
  for ( ; i < stop; ++i )
  {
    if ( kids->m_data[ i ] != win->m_wid )
      return zxwin.getWindow( kids->m_data[ i ] );
  }
  return zxwin.getNext( base, false );
}
ZXSYS zxWINDOW* zxWINDOW_getPrev( zxWINDOW *win )
{
  zxWINDOW *base;
  zxvUI *kids;
  zxui i, stop;
  ZXASSERT( !win ) return zxwin.getRootWindow();
  base = zxwin.getWindow( win->m_base );
  if ( !base )
    return win;
  kids = &base->m_kids;
  stop = zxv_ui.size( kids );
  for ( i = stop - 1; i < stop; --i, --stop )
  {
    if ( kids->m_data[ i ] == win->m_wid )
      break;
  }
  if ( i > 0 )
    return zxwin.getWindow( kids->m_data[ i - 1 ] );
  return base;
}
