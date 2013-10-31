#include <zx/event.h>
ZXSYS_EXP ZXEVENT( zxEVENT_onIdle  ) { return zxDefWinEvt; }
ZXSYS_EXP ZXEVENT( zxEVENT_onInit  ) { return zxDefWinEvt; }
ZXSYS_EXP ZXEVENT( zxEVENT_onKill  ) { return zxDefWinEvt; }
ZXSYS_EXP ZXEVENT( zxEVENT_onCmd   ) { return 0; }
ZXSYS_EXP ZXEVENT( zxEVENT_onChar  ) { return 0; }
ZXSYS_EXP ZXEVENT( zxEVENT_onKeyD  ) { return zxDefWinEvt; }
ZXSYS_EXP ZXEVENT( zxEVENT_onKeyU  ) { return zxDefWinEvt; }
ZXSYS_EXP ZXEVENT( zxEVENT_onCurMV ) { return zxDefWinEvt; }
ZXSYS_EXP ZXEVENT( zxEVENT_onCurLD ) { return zxDefWinEvt; }
ZXSYS_EXP ZXEVENT( zxEVENT_onCurMD ) { return zxDefWinEvt; }
ZXSYS_EXP ZXEVENT( zxEVENT_onCurRD ) { return zxDefWinEvt; }
ZXSYS_EXP ZXEVENT( zxEVENT_onCurBD ) { return zxDefWinEvt; }
ZXSYS_EXP ZXEVENT( zxEVENT_onCurLU ) { return zxDefWinEvt; }
ZXSYS_EXP ZXEVENT( zxEVENT_onCurMU ) { return zxDefWinEvt; }
ZXSYS_EXP ZXEVENT( zxEVENT_onCurRU ) { return zxDefWinEvt; }
ZXSYS_EXP ZXEVENT( zxEVENT_onCurBU ) { return zxDefWinEvt; }
ZXSYS_EXP ZXEVENT( zxEVENT_onCurWH ) { return zxDefWinEvt; }
ZXSYS_EXP ZXEVENT( zxEVENT_onFocus )
{
  /*SetFocus( event->m_wh );*/
  return zxDefWinEvt;
}
ZXSYS_EXP ZXEVENT( zxEVENT_onBlur  )
{
  /*KillFocus( event->m_wh );*/
  return zxDefWinEvt;
}
ZXSYS_EXP ZXEVENT( zxEVENT_onShow  ) { return zxDefWinEvt; }
ZXSYS_EXP ZXEVENT( zxEVENT_onHide  ) { return zxDefWinEvt; }
ZXSYS_EXP ZXEVENT( zxEVENT_onMax   ) { return zxDefWinEvt; }
ZXSYS_EXP ZXEVENT( zxEVENT_onMin   ) { return zxDefWinEvt; }
ZXSYS_EXP ZXEVENT( zxEVENT_onRes   ) { return zxDefWinEvt; }
ZXSYS_EXP ZXEVENT( zxEVENT_onShowAct ) { return zxDefWinEvt; }
ZXSYS_EXP ZXEVENT( zxEVENT_onHideAct ) { return zxDefWinEvt; }
ZXSYS_EXP ZXEVENT( zxEVENT_onMaxAct  ) { return zxDefWinEvt; }
ZXSYS_EXP ZXEVENT( zxEVENT_onMinAct  ) { return zxDefWinEvt; }
ZXSYS_EXP ZXEVENT( zxEVENT_onResAct  ) { return zxDefWinEvt; }
ZXSYS_EXP ZXEVENT( zxEVENT_onShowNoa ) { return zxDefWinEvt; }
ZXSYS_EXP ZXEVENT( zxEVENT_onHideNoa ) { return zxDefWinEvt; }
ZXSYS_EXP ZXEVENT( zxEVENT_onMaxNoa  ) { return zxDefWinEvt; }
ZXSYS_EXP ZXEVENT( zxEVENT_onMinNoa  ) { return zxDefWinEvt; }
ZXSYS_EXP ZXEVENT( zxEVENT_onResNoa  ) { return zxDefWinEvt; }
ZXSYS_EXP ZXEVENT( zxEVENT_onOpen ) { return zxDefWinEvt; }
ZXSYS_EXP ZXEVENT( zxEVENT_onShut ) { return zxDefWinEvt; }
ZXSYS_EXP ZXEVENT( zxEVENT_onQuit ) { return 0; }