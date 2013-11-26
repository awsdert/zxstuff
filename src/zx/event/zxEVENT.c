#include "zxevt.h"
zxn_evt const zxevt =
{
  ZXV_NS_DEF( zxvEVT ),
  zxEVENT_onEvent
};
ZXSYS ZXEVENT( zxEVENT_onCurLD )
{
  if ( GetFocus() == event->m_wh )
    return 0;
  SetFocus( event->m_wh );
  event->m_stopEvent = true;
  return 0;
}
ZXSYS ZXEVENT( zxEVENT_onFocus )
{
  /*zxobj.setFocus( event->m_obj );*/
  return 0;
}

