#include <zx/window.h>
ZXSYS int zxWINDOW_freeAll( int returnCode )
{
  zxOBJS *all = zxobj.allObjects();
  zxOBJ  obj;
  size_t i = 0, stop = zxobj.size( all );
  zxWINDOW* win;
  for ( ; i < stop; ++i )
  {
    obj = all->m_data[ i ];
    if ( obj.type != zxOBJ_SYS_WIN )
      continue;
    win = (zxWINDOW*)obj.obj;
    if ( win )
    {
      if ( win->m_uObj.del )
        win->m_uObj.del( win->m_uObj.obj, win->m_uObj.type );
      if ( win->m_wObj.del )
        win->m_wObj.del( win->m_wObj.obj, win->m_win );
      free( win );
      all->m_data[ i ] = zxobj.defObj;
    }
  }
  return zxobj.freeAll( returnCode );
}
