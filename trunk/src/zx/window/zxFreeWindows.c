#include <zx/window.h>
ZXSYS_EXP int zxFreeWindows( int returnCode )
{
  zxWINDOWS *all = zxwin.allWindows();
  size_t i = 0, stop = zx_win.size( all );
  zxWINDOW* win;
  if ( all && stop )
  {
    for ( ; i < stop; ++i )
    {
      win = all->m_data[ i ];
      if ( win )
      {
        if ( win->opDelWinObj )
          win->opDelWinObj( win->m_winObj );
        if ( win->opDelUsrObj )
          win->opDelUsrObj( win->m_usrObj );
        free( win );
        all->m_data[ i ] = NULL;
      }
    }
    zx_win._kill( all );
  }
  return returnCode;
}