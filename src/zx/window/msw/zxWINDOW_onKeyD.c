#include "../zxwin.h"
ZXEVENT( zxWINDOW_onKeyD )
{
  zxWH *wh = zxwh.byHwnd( event->m_wh );
#if ZXMSW
  zxWINDOW *win = NULL;
  WORD vk = LOWORD( event->m_wp );
  if ( wh )
  {
    win = zxwin.byHandle( event->m_wh );
    switch ( vk )
    {
    case VK_ESCAPE:
      if ( !wh->wid )
      {
        event->m_stopEvent = true;
        PostQuitMessage(0);
      }
      break;
  #if 0
    default:
      if ( vk == VK_TAB )
      {
        SetFocus( zxwin.getNext( win, false )->m_wh );
        event->m_stopEvent = true;
      }
  #endif
    }
  }
#endif
  return 0;
}
