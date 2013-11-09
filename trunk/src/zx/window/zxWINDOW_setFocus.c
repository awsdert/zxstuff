/* USER: AWSDERT; DATE: 07/11/2013; TIME: 18:11 */
#include <zx/window.h>
ZXSYS_EXP void zxWINDOW_setFocus( zxWINDOW* win )
{
  zxOBJ obj = zxobj.defObj;
  if ( win )
    zxobj.setFocus( win->m_obj );
  else
    zxobj.setFocus( obj );
}