#include "zxevt.h"
zxn_evt const zxevt =
{
  ZXV_NS_DEF( zxvEVT ),
  zxEVENT__onEvent
};

ZXEVENT( zxEVENT_onFocus )
{
  zxWH *wh = zxwh.byId( event->m_wid );
  zxobj.setFocus( wh->win );
  return 0;
}
ZXEVENT( zxEVENT_onCurLD )
{
#if 1
  zxHwnd  hwnd = NULL;
  zxPOINT pt = {0};
  pt.x = GET_X_LPARAM( event->m_lp );
  pt.y = GET_Y_LPARAM( event->m_lp );
  hwnd = ChildWindowFromPointEx( NULL, pt, CWP_ALL );
  if ( GetFocus() != hwnd )
    SetFocus( hwnd );
#endif
  return 0;
}
ZXEVENT( zxEVENT_onDestroy )
{
  zxWH *wh = zxwh.byId( event->m_wid );
  if ( !event->m_wid )
    PostQuitMessage( 0 );
  zxv_ui._kill( &wh->objs );
  mset( wh, 0, sizeof( zxWH ) );
  return 0;
}

ZXEVENT( zxEVENT_onEvent )
{
  switch ( event->m_msg )
  {
  case ZXWM_DESTROY:
    return zxEVENT_onDestroy( event );
#if 0
  case ZXWM_FOCUS:
    return zxEVENT_onFocus( event );
#endif
#if 1
  case ZXWM_CURLD:
    return zxEVENT_onCurLD( event );
#endif
  }
  return 0;
}
