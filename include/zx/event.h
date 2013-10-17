#include "app.h"

#ifndef ZX_EVENT_H
#define ZX_EVENT_H

#if ZXMSW
#define zxDefWinEvt DefWindowProc( \
  event->m_wh, event->m_mswMsg, event->m_mswWP, event->m_mswLP )
#define zxEvtCBR    LRESULT
ZXSYS zxEvtCBR CALLBACK
  zxroot_onEvent( zxHwnd wh, UINT msg, WPARAM wp, LPARAM lp );
#else
#define zxDefWinEvt 0
#define zxEvtCBR    zxsl
ZXSYS zxEvtCBR __stdcall
  zxroot_onEvent( zxHwnd wh, zxul msg, zxul *wp, zxul *lp );
#endif

typedef enum zxEVT_enum
{
  zxEVT_IDLE = 0u,
  zxEVT_INIT,
  zxEVT_KILL,
  zxEVT_CHAR,
  zxEVT_KEYU,
  zxEVT_KEYD,
  zxEVT_CURMV,
  zxEVT_CURLD,
  zxEVT_CURMD,
  zxEVT_CURRD,
  zxEVT_CURBD,
  zxEVT_CURLU,
  zxEVT_CURMU,
  zxEVT_CURRU,
  zxEVT_CURBU,
  zxEVT_CURWH,
  zxEVT_FOCUS,
  zxEVT_BLUR,
  zxEVT_SHOW,
  zxEVT_HIDE,
  zxEVT_MAX,
  zxEVT_MIN,
  zxEVT_RES,
  zxEVT_SHOW_ACT,
  zxEVT_HIDE_ACT,
  zxEVT_MAX_ACT,
  zxEVT_MIN_ACT,
  zxEVT_RES_ACT,
  zxEVT_SHOW_NOA,
  zxEVT_HIDE_NOA,
  zxEVT_MAX_NOA,
  zxEVT_MIN_NOA,
  zxEVT_RES_NOA,
  zxEVT_OPEN,
  zxEVT_SHUT,
  zxEVT_QUIT,
  zxEVT_COUNT
} zxEVT;

typedef struct zxEVENT_struct
{
  zxHwnd m_wh;
  zxEVT  m_evt;
  void*  m_ptr;
  zxul   m_ptrType; /* 0 if zxWINDOW */
  bool   m_stopEvent;
  size_t m_wid;
#if ZXMSW
  UINT   m_mswMsg;
  WPARAM m_mswWP;
  LPARAM m_mswLP;
#endif
} zxEVENT;

#define ZXEVENT( NAME ) zxEvtCBR NAME##( zxEVENT *event )
typedef ZXEVENT( (*zxEvtPtr) );

typedef struct zxEVTPTR_struct
{
  zxEVT    type;
  zxEvtPtr event;
} zxEVTPTR;

typedef struct zxEVENTS_struct
{
  zxVECTOR  m_data;
  zxEVTPTR* m_evts;
} zxEVENTS;

ZXSYS ZXEVENT( zxroot_onIdle  );
ZXSYS ZXEVENT( zxroot_onInit  );
ZXSYS ZXEVENT( zxroot_onKill  );
ZXSYS ZXEVENT( zxroot_onChar  );
ZXSYS ZXEVENT( zxroot_onKeyD  );
ZXSYS ZXEVENT( zxroot_onKeyU  );
ZXSYS ZXEVENT( zxroot_onCurMV );
ZXSYS ZXEVENT( zxroot_onCurLD );
ZXSYS ZXEVENT( zxroot_onCurMD );
ZXSYS ZXEVENT( zxroot_onCurRD );
ZXSYS ZXEVENT( zxroot_onCurBD );
ZXSYS ZXEVENT( zxroot_onCurLU );
ZXSYS ZXEVENT( zxroot_onCurMU );
ZXSYS ZXEVENT( zxroot_onCurRU );
ZXSYS ZXEVENT( zxroot_onCurBU );
ZXSYS ZXEVENT( zxroot_onCurWH );
ZXSYS ZXEVENT( zxroot_onFocus );
ZXSYS ZXEVENT( zxroot_onBlur  );
ZXSYS ZXEVENT( zxroot_onShow  );
ZXSYS ZXEVENT( zxroot_onHide  );
ZXSYS ZXEVENT( zxroot_onMax   );
ZXSYS ZXEVENT( zxroot_onMin   );
ZXSYS ZXEVENT( zxroot_onRes   );
ZXSYS ZXEVENT( zxroot_onShowAct );
ZXSYS ZXEVENT( zxroot_onHideAct );
ZXSYS ZXEVENT( zxroot_onMaxAct  );
ZXSYS ZXEVENT( zxroot_onMinAct  );
ZXSYS ZXEVENT( zxroot_onResAct  );
ZXSYS ZXEVENT( zxroot_onShowNoa );
ZXSYS ZXEVENT( zxroot_onHideNoa );
ZXSYS ZXEVENT( zxroot_onMaxNoa  );
ZXSYS ZXEVENT( zxroot_onMinNoa  );
ZXSYS ZXEVENT( zxroot_onResNoa  );
ZXSYS ZXEVENT( zxroot_onOpen );
ZXSYS ZXEVENT( zxroot_onShut );
ZXSYS ZXEVENT( zxroot_onQuit );

static zxEvtPtr zxroot_events[ zxEVT_COUNT ] =
{
  zxroot_onIdle,
  zxroot_onInit,
  zxroot_onKill,
  zxroot_onChar,
  zxroot_onKeyD,
  zxroot_onKeyU,
  zxroot_onCurMV,
  zxroot_onCurLD,
  zxroot_onCurMD,
  zxroot_onCurRD,
  zxroot_onCurBD,
  zxroot_onCurLU,
  zxroot_onCurMU,
  zxroot_onCurRU,
  zxroot_onCurBU,
  zxroot_onCurWH,
  zxroot_onFocus,
  zxroot_onBlur,
  zxroot_onShow,
  zxroot_onHide,
  zxroot_onMax,
  zxroot_onMin,
  zxroot_onRes,
  zxroot_onShowAct,
  zxroot_onHideAct,
  zxroot_onMaxAct,
  zxroot_onMinAct,
  zxroot_onResAct,
  zxroot_onShowNoa,
  zxroot_onHideNoa,
  zxroot_onMaxNoa,
  zxroot_onMinNoa,
  zxroot_onResNoa,
  zxroot_onOpen,
  zxroot_onShut,
  zxroot_onQuit
};

/*
  These are not meant to be used in regular code;
  Create functions for the object holding a
  zxEVENTS object so that it may call these.
*/

ZXSYS bool zxAddEvent( zxEVENTS* events, zxEVTPTR event );
ZXSYS void zxRemEvent( zxEVENTS* events, zxEVTPTR event );

#endif