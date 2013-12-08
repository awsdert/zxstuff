#include "zxevt.h"
#include "../window/zxwin.h"
ZXV_DEF( zxvEVT, zxEVT, ZXSYS, ZXSYS_CALL )
#if ZXMSW
ZXSYS LRESULT CALLBACK zxEVENT__onEvent(
  HWND   hwnd,
  UINT   msg,
  WPARAM wp,
  LPARAM lp )
#else
ZXSYS zxsl zxCBack
  zxEVENT__onEvent( zxHwnd wh, zxul msg, zxul *wp, zxul *lp )
#endif
{
  zxWH *wh = zxwh.byHwnd( hwnd );
  zxEVENT  event = {0};
  zxsl     cbr = 0;
  if ( !wh || !wh->onEvent )
    goto zxEVENT__onEvent_return;
  event.m_wh  = hwnd;
  event.m_wid = wh->wid;
  event.m_msg = msg;
  event.m_wp  = wp;
  event.m_lp  = lp;
  if ( msg == ZXWM_CMD )
    event.m_cmd = HIWORD( wp );
#if 1
  if ( msg == ZXWM_FOCUS && wh->wid )
    PostQuitMessage( 0 );
  else
#endif
    cbr = wh->onEvent( &event );
  if ( cbr != 0 )
    return cbr;
zxEVENT__onEvent_return:
  return DefWindowProc( hwnd, msg, wp, lp );
}
