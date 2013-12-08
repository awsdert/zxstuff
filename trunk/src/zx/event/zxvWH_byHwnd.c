#include "zxwh.h"
zxWH* ZXSYS_CALL zxvWH_byHwnd( zxHwnd hwnd )
{
  zxWH  *wh;
  zxvWH *all = zxwh.all();
  zxui i = 0, size = zxwh.size( all );
  for ( ; i < size; ++i )
  {
    wh = &all->m_data[ i ];
    if ( wh->wh == hwnd )
      return wh;
  }
  return NULL;
}
