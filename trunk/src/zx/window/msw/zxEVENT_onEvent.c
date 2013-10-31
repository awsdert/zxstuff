#include <zx/window.h>
ZXV_DEF( zxEVENTS, zxEVTPTR, ZXSYS_EXP )
#if ZXMSW
ZXSYS_EXP zxEvtCBR zxCBack zxEVENT_onEvent(
  HWND   wh,
  UINT   msg,
  WPARAM wp,
  LPARAM lp )
{
  zxWINDOW  *win = zxwin.byHandle( wh );
  /*PAINTSTRUCT ps = {0}; */
  zxEVENT  event = {0};
  zxEVENTS *evts = NULL;
  zxEVTPTR   ptr = {zxEVT_IDLE};
  zxEvtCBR   cbr = 0;
  size_t i = 0, stop;
  event.m_wh      = wh;
  event.m_mswMsg  = msg;
  event.m_mswWP   = wp;
  event.m_mswLP   = lp;
  if ( !win )
    win = zxwin.getWindow( 0 );
  if ( !win )
    return DefWindowProc( wh, msg, wp, lp );
  switch( msg )
  {
  case WM_PAINT: event.m_evt = zxEVT_COUNT;
    /*
    BeginPaint( wh, &ps);
    EndPaint(   wh, &ps);
    */
    break;
#if 1
  case WM_SETFOCUS:  event.m_evt = zxEVT_FOCUS; break;
#endif
#if 0
  case WM_KILLFOCUS: event.m_evt = zxEVT_BLUR;  break;
#endif
#if 1
  case WM_CHAR:      event.m_evt = zxEVT_CHAR;  break;
  case WM_KEYDOWN:   event.m_evt = zxEVT_KEYD;  break;
#endif
#if 0
  case WM_LBUTTONUP: event.m_evt = zxEVT_CURLU; break;
  case WM_KEYUP:     event.m_evt = zxEVT_KEYU;  break;
  case WM_CREATE:    event.m_evt = zxEVT_OPEN;  break;
#endif
  case WM_DESTROY:   event.m_evt = zxEVT_COUNT;
    if ( !win->m_wid )
      PostQuitMessage(0);
    break;
  case WM_QUIT:      event.m_evt = zxEVT_QUIT;
    zxFreeWindows(0);
    break;
  default:           event.m_evt = zxEVT_COUNT;
  }
  event.m_wid = win->m_wid;
  if ( event.m_evt < zxEVT_COUNT )
  {
    evts = &win->m_events;
    stop = zxevt.size( evts );
    for ( ; i < stop; ++i )
    {
      ptr = evts->m_data[ i ];
      if ( ptr.type == event.m_evt )
        cbr = ptr.proc( &event );
      if ( cbr != 0 )
        return cbr;
      if ( event.m_stopEvent )
        return 0;
    }
    evts = zxevt.getDefEvents();
    stop = zxevt.size( evts );
    for ( i = stop - 1; i < stop; --i, --stop )
    {
      ptr = evts->m_data[ i ];
      if ( ptr.type == event.m_evt )
        cbr = ptr.proc( &event );
      if ( cbr != 0 )
        return cbr;
      if ( event.m_stopEvent )
        return 0;
    }
    return 0;
  }
  return DefWindowProc( wh, msg, wp, lp );
}
#else
ZXSYS_EXP zxEvtCBR zxCBack
  zxEVENT_onEvent( zxHwnd wh, zxul msg, zxul *wp, zxul *lp )
  { return 0; }
#endif