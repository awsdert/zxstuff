#include <zx/window.h>
#if ZXMSW
zxsl zxWINDOW_onKeyD( zxEVENT* event )
{
  WORD vk = LOWORD( event->m_mswWP );
  zxWINDOW *win;
  if ( !event->m_ptrType && event->m_ptr )
  {
    win  = (zxWINDOW*)event->m_ptr;
    switch ( vk )
    {
    case VK_ESCAPE:
      PostQuitMessage(0);
      break;
    default:
  #if 1
      if ( win->m_win == zxWIN_NULL )
      {
        if ( vk == VK_TAB && zxv_size.size( &win->m_kids ) )
          SetFocus( (*zx_win.at( zxwin.allWindows(), win->m_kids.m_data[ 0 ] ))->m_wh );
      }
      else
  #endif
        return 0;
    }
  }
  return 0;
}
#endif
