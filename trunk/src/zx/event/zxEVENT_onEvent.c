#include <zx/window.h>
ZXV_DEF( zxevt, zxEVENTS, zxEVTPTR, ZXSYS, ZXSYS_CALL )
#if ZXMSW
ZXSYS LRESULT CALLBACK zxEVENT_onEvent(
  HWND   wh,
  UINT   msg,
  WPARAM wp,
  LPARAM lp )
{
  zxWINDOW  *win = zxwin.getFocus();
  /*PAINTSTRUCT ps = {0}; */
  zxEVENT  event = {0};
  zxEVENTS *evts = NULL;
  zxEVTPTR   ptr = {zxEVT_IDLE};
  zxsl   cbr = 0;
  size_t i = 0, stop;
  event.m_wh      = wh;
  event.m_mswMsg  = msg;
  event.m_mswWP   = wp;
  event.m_mswLP   = lp;
  if ( !win )
    win = zxwin.getRootWindow();
  if ( !win )
    return DefWindowProc( wh, msg, wp, lp );
  switch( msg )
  {
  case WM_PAINT:
    event.m_evt = zxEVT_PAINT;
    break;
  case WM_NCPAINT:
    event.m_evt = zxEVT_PAINTNC;
    break;
  case WM_ACTIVATE:
    event.m_evt = zxEVT_ACTIVATE;
    break;
  case WM_SETFOCUS:
    event.m_evt = zxEVT_FOCUS;
    break;
  case WM_KILLFOCUS:
    event.m_evt = zxEVT_BLUR;
    break;
  case WM_CHAR:
    event.m_evt = zxEVT_CHAR;
    break;
  case WM_KEYDOWN:
    event.m_evt = zxEVT_KEYD;
    break;
  case WM_KEYUP:
    event.m_evt = zxEVT_KEYU;
    break;
  case WM_LBUTTONUP:
    event.m_evt = zxEVT_CURLU;
    break;
  case WM_LBUTTONDOWN:
    event.m_evt = zxEVT_CURLD;
    break;
  case WM_CREATE:
    event.m_evt = zxEVT_CREATE;
    break;
  case WM_DESTROY:
    event.m_evt = zxEVT_DESTROY;
    if ( !win->m_obj.gid )
      PostQuitMessage(0);
    break;
  case WM_QUIT:
    event.m_evt = zxEVT_QUIT;
    zxwin.freeAll(0);
    break;
  default:
    event.m_evt = zxEVT_COUNT;
  }
  event.m_obj.gid = win->m_obj.gid;
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
  }
  return DefWindowProc( wh, msg, wp, lp );
}
#else
ZXSYS zxsl zxCBack
  zxEVENT_onEvent( zxHwnd wh, zxul msg, zxul *wp, zxul *lp )
  { return 0; }
#endif
