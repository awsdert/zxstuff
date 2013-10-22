#include <zx/window.h>
#if ZXMSW
zxEvtCBR zxv_zxWINDOW_onKeyD( zxEVENT* event )
{
  WORD vk = LOWORD( event->m_mswWP );
  zxWINDOW *win;
  size_t i = 0, stop = 0;
  zxEVTPTR ptr;
  zxEvtCBR cbr = 0;
  if ( !event->m_ptrType && event->m_ptr )
  {
    win  = (zxWINDOW*)event->m_ptr;
    stop = zxevt.size( &win->m_events );
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
      else if ( win->m_events.m_data )
      {
        for ( ; i < stop; ++i )
        {
          ptr = win->m_events.m_data[ i ];
          if ( ptr.type == zxEVT_KEYD )
             return ptr.event( event );
        }
      }
      else
  #endif
        return zxDefWinEvt;
    }
  }
  return 0;
}
#endif
