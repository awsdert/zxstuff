#include <zx/window.h>
#if ZXMSW
zxEvtCBR zxOnKeyD( zxWINDOW* win, zxEVENT* event )
{
  WORD vk = LOWORD( event->m_mswWP );
  switch ( vk )
  {
  case VK_ESCAPE:
    PostQuitMessage(0);
    break;
  default:
#if 1
    if ( win->m_winType == zxWIN_NULL )
    {
      if ( vk == VK_TAB )
        SetFocus( win->m_kids[0]->m_hdl );
    }
    else if ( win->m_onKeyD )
      return win->m_onKeyD( win, event );
    else
#endif
      return zxDefWinEvt;
  }
  return 0;
}
#endif
