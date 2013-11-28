#include "zxwin.h"
ZXSYS int zxWINDOW_freeAll( int returnCode )
{
  zxvWH  *all  =  zxwh.all();
  zxOBJ   obj;
  zxWH   *wh;
  size_t i = 0, stop = zxwh.size( all );
  zxWINDOW* win;
  for ( ; i < stop; ++i )
  {
    wh = &all->m_data[ i ];
    obj= wh->win;
    zxv_size._kill( &wh->objs );
    *wh = zxwh.defWH;
    if ( obj.type != zxOBJ_SYS_WIN )
      continue;
    win = zxwin.opDel( (zxWINDOW*)obj.obj );
  }
  return zxobj.freeAll( returnCode );
}
