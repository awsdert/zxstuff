#include "zxwin.h"
ZXSYS zxWINDOW* zxWINDOW_opDel( zxWINDOW* win )
{
  zxvOBJ *all = zxobj.all();
  zxui i = 0, stop = zxobj.size( all );
  zxWH *wh = NULL;
  zxOBJ obj = {0};
   /* This reduces thread/parallel issues */
  if ( !win ) return win;
  wh = zxwh.byId( win->m_wid );
  if ( !wh ) return win;
  obj = wh->win;
  if ( obj.id >= stop || !all->m_data[ obj.id ].type )
    return win;
  all->m_data[ win->m_wid ] = zxobj.defObj;
  /* Onto actually deleting the object */
  if ( win->m_uObj.del )
    win->m_uObj.del( win->m_uObj.obj, win->m_uObj.type );
  if ( win->m_wObj.del )
    win->m_wObj.del( win->m_wObj.obj, win->m_wObj.type );
  if ( win->m_delKids )
  {
    stop = zxv_ui.size( &win->m_kids );
    for ( ; i < stop; ++i )
      zxwin.opDel( zxwin.getWindow( win->m_kids.m_data[ i ] ) );
  }
  zxv_ui._kill( &win->m_kids );
  if ( !win->m_class )
  {
    *win = zxwin.def;
    free( win );
    win = NULL;
  }
  if ( IsWindow( wh->wh ) )
    DestroyWindow( wh->wh );
  return win;
}
