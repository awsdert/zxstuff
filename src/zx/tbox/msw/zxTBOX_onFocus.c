#include "../zxtbox.h"
ZXEVENT( zxTBOX_onFocus )
{
  zxWINDOW *win = zxwin.getWindow( event->m_wid );
  zxTBOX  *tbox = NULL;
  if ( !win || win->m_win != zxWIN_TBOX )
    return zxWINDOW_onEvent( event );
  tbox = (zxTBOX*)win->m_wObj.obj;
  zxtbox._setText( tbox );
  return zxWINDOW_onEvent( event );
}
