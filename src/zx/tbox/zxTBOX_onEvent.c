#include "zxtbox.h"
zxn_tbox const zxtbox =
{
  {0},
  zxTBOX__setText,
  zxTBOX__drawText,
  zxTBOX__setCaret,
  zxTBOX_opNew,
  zxTBOX_opDel
};

ZXEVENT( zxTBOX_onEvent )
{
  switch ( event->m_msg )
  {
  case ZXWM_CMD:   return zxTBOX_onCmd(   event );
  case ZXWM_CHAR:  return zxTBOX_onChar(  event );
  case ZXWM_FOCUS: return zxTBOX_onFocus( event );
  }
  return zxWINDOW_onEvent( event );
}
