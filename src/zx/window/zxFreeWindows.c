#include <zx/window.h>
ZXSYS_EXP int zxFreeWindows( int returnCode )
{
  zxVECTOR *data = zxwin.allWindows();
  size_t i = 0, stop = data->m_count;
  zxWINDOW* win, **ary = (zxWINDOW**)data->m_data;
  if ( ary && stop )
  {
    for ( ; i < stop; ++i )
    {
      win = ary[ i ];
      if ( win )
      {
        free( win );
        ary[ i ] = NULL;
      }
    }
    zxv._kill( data );
  }
  return returnCode;
}