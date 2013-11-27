#include "zxwin.h"
ZXSYS zxWCX zxWINDOW_defWCX( size_t type )
{
  zxWCX wcx = {0};
#if ZXMSW
  wcx.hInstance     = zxGetThisI();
  wcx.cbSize        = sizeof(zxWCX);
  wcx.hbrBackground = (HBRUSH)(COLOR_WINDOW);
  wcx.lpszClassName = WC_STATIC;
  wcx.lpfnWndProc   = zxevt.onEvent;
  switch ( type )
  {
  case zxWIN_TBOX:
    wcx.lpszClassName = WC_EDIT;
    wcx.hbrBackground = (HBRUSH)(COLOR_WINDOWFRAME);
  }
#endif
  return wcx;
}
ZXEVENT( zxWINDOW_onDestroy )
{
  zxWH *wh = zxwh.byId( event->m_wid );
  if ( wh && !wh->wid )
    PostQuitMessage( 0 );
  return 0;
}
ZXEVENT( zxWINDOW_onQuit )
{
  return zxwin.freeAll( 0 );
}
ZXEVENT( zxWINDOW_onCurLD )
{
  if ( GetFocus() != event->m_wh )
    SetFocus( event->m_wh );
  return 0;
}
ZXEVENT( zxWINDOW_onEvent )
{
  switch ( event->m_msg )
  {
    case ZXWM_DESTROY:
      return zxWINDOW_onDestroy( event );
    case ZXWM_CURLD:
      return zxWINDOW_onCurLD(   event );
    case ZXWM_QUIT:
      return zxWINDOW_onQuit(    event );
    case ZXWM_KEYD:
      return zxWINDOW_onKeyD(    event );
  }
  return 0;
}
