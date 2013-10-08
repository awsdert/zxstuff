#include <zx/window.h>
zxWINDOW **zx_l_windows = NULL;
ZXSYS_EXP zxWINDOW** zxGetAllWindows( void ) { return zx_l_windows; }
ZXSYS_EXP void zx_SetAllWindows( zxWINDOW **newArray ) { zx_l_windows = newArray; }
ZXSYS_EXP int zxFreeWindows( int returnCode )
{
  zxuint i = 0u, count = zxGetWindowCount();
  zxWINDOW* win;
  if ( zx_l_windows != NULL && count > 0u )
  {
    for ( ; i < count; ++i )
    {
      win = zx_l_windows[ i ];
      if ( win != NULL )
      {
        if ( win->m_kids != NULL )
          free( win->m_kids );
        free( zx_l_windows[ i ] );
        zx_l_windows[ i ] = NULL;
      }
    }
    free( zx_l_windows );
    zx_l_windows = NULL;
    zx_SetWindowCount( 0u );
  }
  return returnCode;
}