/* USER: AWSDERT DATE: 07/11/2013; TIME: 18:05 */
#include <zx/window.h>
ZXSYS zxWINDOW* zxWINDOW_getFocus( void )
{
  zxOBJ obj = zxobj.getFocus();
  if ( obj.type == zxOBJ_SYS_WIN )
    return (zxWINDOW*)obj.obj;
  return NULL;
}
