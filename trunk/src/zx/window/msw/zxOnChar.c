#include <zx/window.h>
#if ZXMSW
zxEvtCBR zxOnChar( zxWINDOW* win, zxEVENT* event )
{
  if ( win->m_onChar )
    return win->m_onChar( win, event );
  else
    return zxDefWinEvt;
}
#endif
