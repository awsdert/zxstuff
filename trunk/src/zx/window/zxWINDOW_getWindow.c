#include <zx/window.h>
ZXSYS_EXP zxWINDOW* zxv_zxWINDOW_getWindow( size_t id )
{
  zxWINDOWS *all = zxwin.allWindows();
  if ( id < zx_win.size( all ) )
    return all->m_data[ id ];
  return NULL;
}