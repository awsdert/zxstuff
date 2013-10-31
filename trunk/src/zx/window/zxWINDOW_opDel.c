#include <zx/window.h>
ZXSYS_EXP zxWINDOW* zxWINDOW_opDel( zxWINDOW* win )
{
  zxWINDOWS *all = zxwin.allWindows();
  size_t i = 0, stop = zx_win.size( all );
  if ( !win || win->m_wid > stop || !all->m_data[ win->m_wid ] )
    return win; /* This reduces thread/parallel issues */
  all->m_data[ win->m_wid ] = NULL;
  if ( win->opDelUsrObj )
    win->opDelUsrObj( win->m_usrObj );
  if ( win->opDelWinObj )
    win->opDelWinObj( win->m_winObj );
  if ( win->m_delKids )
  {
    stop = zxv_size.size( &win->m_kids );
    for ( ; i < stop; ++i )
      zxwin.opDel( all->m_data[ win->m_kids.m_data[ i ] ] );
  }
  zxv_size._kill( &win->m_kids );
  if ( !win->m_class )
  {
    free( win );
    win = NULL;
  }
  return win;
}