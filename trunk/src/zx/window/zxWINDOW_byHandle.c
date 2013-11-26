#include "zxwin.h"
ZXSYS zxWINDOW* zxWINDOW_byHandle( zxHwnd hwnd )
{
  zxWH     *wh  = zxwh.byHwnd( hwnd );
  zxWINDOW *win = NULL;
  if ( wh->win.type == zxOBJ_SYS_WIN )
    win = (zxWINDOW*)wh->win.obj;
  return win;
}
