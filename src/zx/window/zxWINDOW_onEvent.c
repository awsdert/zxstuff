#include "zxwin.h"

ZXEVENT( zxWINDOW_onQuit )
{
  return zxwin.freeAll( 0 );
}
ZXEVENT( zxWINDOW_onEvent )
{
  switch ( event->m_msg )
  {
    case ZXWM_QUIT:
      return zxWINDOW_onQuit(    event );
    case ZXWM_KEYD:
      return zxWINDOW_onKeyD(    event );
  }
  return zxEVENT_onEvent( event );
}
