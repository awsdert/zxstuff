#include <zx/window.h>
ZXSYS_EXP int zxFreeWindows( int returnCode )
{
  zxVECTOR *data = zxwin.allWindows();
  size_t i = 0, stop = data->m_count;
  zxWINDOW* win, **windows = (zxWINDOW**)data->m_data;
  if ( windows && stop )
  {
    for ( ; i < stop; ++i )
    {
      win = windows[ i ];
      if ( win )
      {
        if ( win->m_core )
          free( win->m_core );
        free( win );
        windows[ i ] = NULL;
      }
    }
    zxv._kill( data );
  }
  return returnCode;
}