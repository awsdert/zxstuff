#include "zxwin.h"
ZXSYS int zxWINDOW_freeAll( int returnCode )
{
  zxvWH  *all  =  zxwh.all();
  zxOBJ   obj;
  zxWH    wh;
  size_t i = 0, stop = zxwh.size( all );
  zxWINDOW* win;
  for ( ; i < stop; ++i )
  {
    wh = all->m_data[ i ];
    obj= wh.win;
    if ( obj.type != zxOBJ_SYS_WIN )
      continue;
    win = zxwin.opDel( (zxWINDOW*)obj.obj );
    if ( !win )
      all->m_data[ i ] = zxwh.defWH;
  }
  return zxobj.freeAll( returnCode );
}
