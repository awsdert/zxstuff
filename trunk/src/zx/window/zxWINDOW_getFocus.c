/* USER: AWSDERT DATE: 07/11/2013; TIME: 18:05 */
#include "zxwin.h"
ZXSYS zxWINDOW* zxWINDOW_getFocus( void )
{
  zxWH *wh = zxwh.byHwnd( GetFocus() );
  zxOBJ obj = {0};
  if ( wh )
    obj = wh->win;
  if ( obj.type == zxOBJ_SYS_WIN )
    return (zxWINDOW*)obj.obj;
  return NULL;
}
