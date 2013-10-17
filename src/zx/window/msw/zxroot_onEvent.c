#include <zx/window.h>
#if ZXMSW
LRESULT CALLBACK zxroot_onEvent(
  HWND   wh,
  UINT   msg,
  WPARAM wp,
  LPARAM lp )
{
  zxWINDOW *win = zxwin.byHandle( wh );
  zxEVENT  event;
  zxEVTPTR ptr;
  zxEvtCBR cbr = 0;
  size_t i = 0, stop;
  event.m_wh      = wh;
  event.m_mswMsg  = msg;
  event.m_mswWP   = wp;
  event.m_mswLP   = lp;
  if ( !win )
    win = zxwin.getWindow( 0 );
  switch( msg )
  {
  case WM_LBUTTONUP: event.m_evt = zxEVT_CURLU;
    SetFocus( wh );
    return 0;
#if 1
  case WM_SETFOCUS:  event.m_evt = zxEVT_FOCUS; break;
  case WM_KILLFOCUS: event.m_evt = zxEVT_BLUR;
    HideCaret( wh );
    DestroyCaret();
    return DefWindowProc( wh, msg, wp, lp );
#endif
  case WM_CHAR:      event.m_evt = zxEVT_CHAR;  break;
  case WM_KEYDOWN:   event.m_evt = zxEVT_KEYD;  break;
  case WM_DESTROY:
    PostQuitMessage(0);
    break;
  case WM_QUIT:      event.m_evt = zxEVT_QUIT;
    zxFreeWindows(0);
  default:
    event.m_evt = zxEVT_COUNT;
  }
  event.m_wid = win->m_wid;
  if ( event.m_evt < zxEVT_COUNT )
  {
    stop = win->m_events.m_data.m_count;
    for ( ; i < stop; ++i )
    {
      ptr = win->m_events.m_evts[ i ];
      if ( ptr.type == event.m_evt )
        cbr = ptr.event( &event );
      if ( cbr != 0 )
        return cbr;
      if ( event.m_stopEvent )
        return DefWindowProc( wh, msg, wp, lp );
    }
    return win->m_defEvts[ event.m_evt ]( &event );
  }
  return DefWindowProc( wh, msg, wp, lp );
}
#endif