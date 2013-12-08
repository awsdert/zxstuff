#include "zxwin.h"
ZXSYS int zxWINDOW_freeAll( int returnCode )
{
  zxvWH  *all  =  zxwh.all();
  zxOBJ   obj;
  zxWH   *wh;
  zxui i = 0, stop = zxwh.size( all );
  zxWINDOW* win;
  if ( stop )
  {
    do
    {
      wh = &all->m_data[ i ];
      obj= wh->win;
      zxv_ui._kill( &wh->objs );
      if ( obj.type != zxOBJ_SYS_WIN )
        continue;
      win = zxwin.opDel( (zxWINDOW*)obj.obj );
      mset( wh, 0, sizeof( zxWH ) );
      ++i;
    }
    while ( i < stop );
  }
  return zxobj.freeAll( returnCode );
}
