#include <zx/window.h>
ZXSYS ZXEVENT( zxEVENT_onIdle  )   { return 0; }
ZXSYS ZXEVENT( zxEVENT_onInit  )   { return 0; }
ZXSYS ZXEVENT( zxEVENT_onKill  )   { return 0; }
ZXSYS ZXEVENT( zxEVENT_onCmd   )   { return 0; }
ZXSYS ZXEVENT( zxEVENT_onChar  )   { return 0; }
ZXSYS ZXEVENT( zxEVENT_onKeyD  )   { return 0; }
ZXSYS ZXEVENT( zxEVENT_onKeyU  )   { return 0; }
ZXSYS ZXEVENT( zxEVENT_onCurMV )   { return 0; }
ZXSYS ZXEVENT( zxEVENT_onCurLD )   { return 0; }
ZXSYS ZXEVENT( zxEVENT_onCurMD )   { return 0; }
ZXSYS ZXEVENT( zxEVENT_onCurRD )   { return 0; }
ZXSYS ZXEVENT( zxEVENT_onCurBD )   { return 0; }
ZXSYS ZXEVENT( zxEVENT_onCurLU )   { return 0; }
ZXSYS ZXEVENT( zxEVENT_onCurMU )   { return 0; }
ZXSYS ZXEVENT( zxEVENT_onCurRU )   { return 0; }
ZXSYS ZXEVENT( zxEVENT_onCurBU )   { return 0; }
ZXSYS ZXEVENT( zxEVENT_onCurWH )   { return 0; }
ZXSYS ZXEVENT( zxEVENT_onFocus )
{
  zxobj.setFocus( event->m_obj );
  return 0;
}
ZXSYS ZXEVENT( zxEVENT_onBlur  )    { return 0; }
ZXSYS ZXEVENT( zxEVENT_onShow  )    { return 0; }
ZXSYS ZXEVENT( zxEVENT_onHide  )    { return 0; }
ZXSYS ZXEVENT( zxEVENT_onMax   )    { return 0; }
ZXSYS ZXEVENT( zxEVENT_onMin   )    { return 0; }
ZXSYS ZXEVENT( zxEVENT_onRes   )    { return 0; }
ZXSYS ZXEVENT( zxEVENT_onActivate ) { return 0; }
ZXSYS ZXEVENT( zxEVENT_onDisivate ) { return 0; }
ZXSYS ZXEVENT( zxEVENT_onEnable  )  { return 0; }
ZXSYS ZXEVENT( zxEVENT_onDisable  ) { return 0; }
ZXSYS ZXEVENT( zxEVENT_onCreate )   { return 0; }
ZXSYS ZXEVENT( zxEVENT_onDestroy )  { return 0; }
ZXSYS ZXEVENT( zxEVENT_onQuit )     { return 0; }
ZXSYS ZXEVENT( zxEVENT_onPaint )    { return 0; }
ZXSYS ZXEVENT( zxEVENT_onPaintNC )  { return 0; }
