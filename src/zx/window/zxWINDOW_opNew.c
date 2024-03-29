#include "zxwin.h"
ZXSYS zxWINDOW* zxWINDOW_opNew( zxWINDOW* win )
{
  zxvWH *all = zxwh.all();
  zxWH wh = {0};
  zxOBJ *obj = NULL;
  zxui i = 0, stop = zxwh.size( all );
  if ( !win )
    win = (zxWINDOW*)mnew( sizeof( zxWINDOW ), NULL );
  if ( stop )
  {
    do
    {
      if ( !all->m_data[ i ].wh )
        break;
      ++i;
    }
    while ( i < stop );
  }
  if ( i == stop )
    zxwh.grow( all, i + 1, wh );
  /* Window */
  *win             = zxwin.def;
  zxstr._init(    &win->m_txt,  NULL, 0 );
  zxv_ui._init( &win->m_kids, NULL, 0 );
  win->m_wid       = i;
  win->m_oid       = zxobj.getNewId();
  win->m_wcx       = (zxWCX*)mnew( sizeof( zxWCX ), NULL );
  (*win->m_wcx)    = zxwin.defWCX( zxWIN_NULL );
  /* Object */
  obj = zxobj.at( zxobj.all(), win->m_oid );
  obj->obj          = win;
  obj->type         = zxOBJ_SYS_WIN;
  obj->subType      = zxWIN_NULL;
  /* Handle */
  zxv_ui._init( &wh.objs, NULL, 0 );
  wh.wid           = i;
  wh.win           = *obj;
  wh.onEvent       = zxWINDOW_onEvent;
  all->m_data[ i ] = wh;
  return win;
}
