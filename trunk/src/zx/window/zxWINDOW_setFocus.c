/* USER: AWSDERT; DATE: 07/11/2013; TIME: 18:11 */
#include <zx/window.h>
ZXSYS void zxWINDOW_setFocus( zxWINDOW* win )
{
  zxWH *wh = NULL;
  if ( !win )
    return;
  wh = zxwh.byId( win->m_wid );
  /*
  zxobj.setFocus( wh->objs, win->m_obj );*/
}
