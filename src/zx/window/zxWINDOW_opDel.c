#include <zx/window.h>
ZXSYS_EXP zxWINDOW* zxWINDOW_opDel( zxWINDOW* win )
{
  zxOBJS *all = zxobj.allObjects();
  size_t i = 0, stop = zxobj.size( all );
  if ( !win || win->m_obj.gid > stop || !all->m_data[ win->m_obj.gid ].type )
    return win; /* This reduces thread/parallel issues */
  all->m_data[ win->m_obj.gid ] = zxobj.defObj;
  if ( win->m_uObj.del )
    win->m_uObj.del( win->m_uObj.obj, win->m_uObj.type );
  if ( win->m_wObj.del )
    win->m_wObj.del( win->m_wObj.obj, win->m_wObj.type );
  if ( win->m_delKids )
  {
    stop = zxv_size.size( &win->m_kids );
    for ( ; i < stop; ++i )
      zxwin.opDel( zxwin.getWindow( win->m_kids.m_data[ i ] ) );
  }
  zxv_size._kill( &win->m_kids );
  if ( !win->m_class )
  {
    free( win );
    win = NULL;
  }
  return win;
}