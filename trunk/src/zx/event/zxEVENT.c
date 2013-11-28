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
  zxHwnd  hwnd = NULL;
  zxPOINT pt = {0};
  pt.x = GET_X_LPARAM( event->m_lp );
  pt.y = GET_Y_LPARAM( event->m_lp );
  hwnd = ChildWindowFromPointEx( NULL, pt, CWP_ALL );
  if ( GetFocus() != hwnd )
    SetFocus( hwnd );
  return 0;
}

ZXEVENT( zxEVENT_onEvent )
{
  switch ( event->m_msg )
  {
  case ZXWM_FOCUS:
    return zxEVENT_onFocus( event );
  case ZXWM_CURLD:
    return zxEVENT_onCurLD( event );
  }
  return 0;
}
