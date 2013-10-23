#include <zx/window.h>
ZXSYS_EXP void zxWINDOW_addKid( zxWINDOW *win, zxWINDOW *kid )
{
  size_t kids[1] = { 0 }, i = 0, stop;
  zxvSIZE k = { ZXVECTOR( kids, NULL, true, size_t, 1 ), kids };
  if ( !win || kid )
    return;
  stop = zxv_size.size( &win->m_kids );
  for ( ; i < stop; ++i )
  {
    if ( win->m_kids.m_data[ i ] == kid->m_wid )
      return;
  }
  kids[ 0 ] = kid->m_wid;
  zxv_size.push_back( &win->m_kids, &k );
}