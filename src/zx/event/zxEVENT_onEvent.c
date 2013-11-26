#include "zxevt.h"
ZXV_DEF( zxvEVT, zxEVT, ZXSYS, ZXSYS_CALL )
#if ZXMSW
ZXSYS LRESULT CALLBACK zxEVENT_onEvent(
  HWND   hwnd,
  UINT   msg,
  WPARAM wp,
  LPARAM lp )
#else
ZXSYS zxsl zxCBack
  zxEVENT_onEvent( zxHwnd wh, zxul msg, zxul *wp, zxul *lp )
#endif
{
  zxWH *wh = zxwh.byHwnd( hwnd );
  zxEVENT  event = {0};
  zxsl     cbr = 0;
  if ( !wh || !wh->onEvent )
    return DefWindowProc( hwnd, msg, wp, lp );
  event.m_wh  = hwnd;
  event.m_wid = wh->wid;
  event.m_msg = msg;
  event.m_wp  = wp;
  event.m_lp  = lp;
  cbr = wh->onEvent( &event );
  if ( cbr != 0 )
    return cbr;
  if ( event.m_stopEvent )
    return 0;
  return DefWindowProc( hwnd, msg, wp, lp );
}
