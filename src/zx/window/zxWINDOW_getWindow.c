#include "zxwin.h"
ZXSYS zxWINDOW* zxWINDOW_getWindow( zxui wid )
{
  zxWH *wh = zxwh.byId( wid );
  if ( wh && wh->win.type == zxOBJ_SYS_WIN )
    return (zxWINDOW*)wh->win.obj;
  return NULL;
}
