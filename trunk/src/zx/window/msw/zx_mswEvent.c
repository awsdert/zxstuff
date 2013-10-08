#include <zx/window.h>
#if ZXMSW
LRESULT CALLBACK zx_mswEvent( HWND hdl, UINT msg, WPARAM wp, LPARAM lp )
{
  zxWINDOW *win = zxGetWindowH( hdl );
  zxEVENT  event;
  event.mswHwnd = hdl;
  event.mswMsg  = msg;
  event.mswWP   = wp;
  event.mswLP   = lp;
  if ( !win )
    return DefWindowProc( hdl, msg, wp, lp );
  switch( msg )
  {
  case WM_LBUTTONUP:
    SetFocus( hdl );
    return 0;
#if 1
  case WM_SETFOCUS:
    event.evtType = zxEVT_WIN_FOCUS;
    if ( win->m_onFocus )
      return win->m_onFocus( win, &event );
    return DefWindowProc( hdl, msg, wp, lp );
  case WM_KILLFOCUS:
    HideCaret( hdl );
    DestroyCaret();
    return DefWindowProc( hdl, msg, wp, lp );
#endif
  case WM_CHAR:
    return zxOnChar( win, &event );
  case WM_KEYDOWN:
    return zxOnKeyD( win, &event );
  case WM_DESTROY:
    PostQuitMessage(0);
    break;
  case WM_QUIT:
    zxFreeWindows(0);
  default:
    return DefWindowProc( hdl, msg, wp, lp );
  }
  return 0;
}
#endif