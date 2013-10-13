#include <zx/window.h>
ZXSYS_EXP void zxv_zxWINDOW__kill( zxWINDOW* win )
{
  zxVECTOR *data = zxwin.allWindows();
  zxWINDOW **ary = (zxWINDOW**)data->m_data, **kids;
  zxoWINDOW *core = NULL;
  size_t i = 0, stop;
  if ( !win )
    return;
  core = win->m_core;
  if ( core )
  {
    if ( !ary[ core->m_wid ] )
      return; /* This reduces thread issues */
    ary[ core->m_wid ] = NULL;
    ZXDEL( win->m_core );
  }
  if ( win->m_delKids )
  {
    kids = (zxWINDOW**)win->m_kids.m_data;
    stop = win->m_kids.m_count;
    for ( ; i < stop; ++i )
      zxwin._kill( kids[ i ] );
  }
  zxv._kill( &win->m_kids );
  free( win );
}