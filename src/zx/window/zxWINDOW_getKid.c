#include <zx/window.h>
ZXSYS_EXP zxWINDOW* zxWINDOW_getKid( zxWINDOW *win, size_t i )
{
  if ( !win || !zxv_size.at( &win->m_kids, i ) )
    return NULL;
  return zxwin.getWindow( win->m_kids.m_data[ i ] );
}