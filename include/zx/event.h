#pragma once
#include "app.h"

#ifndef ZX_EVENT_H
#define ZX_EVENT_H

#if ZXMSW
#define zxDefWinEvt DefWindowProc( \
  event->m_wh, event->m_mswMsg, event->m_mswWP, event->m_mswLP )
#define zxEvtCBR    LRESULT
ZXSYS zxEvtCBR CALLBACK
  zxEVENT_onEvent( zxHwnd wh, UINT msg, WPARAM wp, LPARAM lp );
#else
#define zxDefWinEvt 0
#define zxEvtCBR    zxsl
ZXSYS zxEvtCBR __stdcall
  zxEVENT_onEvent( zxHwnd wh, zxul msg, zxul *wp, zxul *lp );
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

ZXV_DEC( zxEVENTS, zxEVTPTR );

ZXV_DEC_2ND( zxEVENTS, zxEVTPTR, ZXSYS );

/*
  These are not meant to be used in regular code;
  Create functions for the object holding an
  events object so that it may call these.
*/

ZXSYS bool zxEVENTS_addEvent( zxEVENTS* events, zxEVTPTR event );
ZXSYS void zxEVENTS_remEvent( zxEVENTS* events, zxEVTPTR event );

ZXSYS ZXEVENT( zxEVENT_onIdle  );
ZXSYS ZXEVENT( zxEVENT_onInit  );
ZXSYS ZXEVENT( zxEVENT_onKill  );
ZXSYS ZXEVENT( zxEVENT_onChar  );
ZXSYS ZXEVENT( zxEVENT_onKeyD  );
ZXSYS ZXEVENT( zxEVENT_onKeyU  );
ZXSYS ZXEVENT( zxEVENT_onCurMV );
ZXSYS ZXEVENT( zxEVENT_onCurLD );
ZXSYS ZXEVENT( zxEVENT_onCurMD );
ZXSYS ZXEVENT( zxEVENT_onCurRD );
ZXSYS ZXEVENT( zxEVENT_onCurBD );
ZXSYS ZXEVENT( zxEVENT_onCurLU );
ZXSYS ZXEVENT( zxEVENT_onCurMU );
ZXSYS ZXEVENT( zxEVENT_onCurRU );
ZXSYS ZXEVENT( zxEVENT_onCurBU );
ZXSYS ZXEVENT( zxEVENT_onCurWH );
ZXSYS ZXEVENT( zxEVENT_onFocus );
ZXSYS ZXEVENT( zxEVENT_onBlur  );
ZXSYS ZXEVENT( zxEVENT_onShow  );
ZXSYS ZXEVENT( zxEVENT_onHide  );
ZXSYS ZXEVENT( zxEVENT_onMax   );
ZXSYS ZXEVENT( zxEVENT_onMin   );
ZXSYS ZXEVENT( zxEVENT_onRes   );
ZXSYS ZXEVENT( zxEVENT_onShowAct );
ZXSYS ZXEVENT( zxEVENT_onHideAct );
ZXSYS ZXEVENT( zxEVENT_onMaxAct  );
ZXSYS ZXEVENT( zxEVENT_onMinAct  );
ZXSYS ZXEVENT( zxEVENT_onResAct  );
ZXSYS ZXEVENT( zxEVENT_onShowNoa );
ZXSYS ZXEVENT( zxEVENT_onHideNoa );
ZXSYS ZXEVENT( zxEVENT_onMaxNoa  );
ZXSYS ZXEVENT( zxEVENT_onMinNoa  );
ZXSYS ZXEVENT( zxEVENT_onResNoa  );
ZXSYS ZXEVENT( zxEVENT_onOpen );
ZXSYS ZXEVENT( zxEVENT_onShut );
ZXSYS ZXEVENT( zxEVENT_onQuit );

static zxEVENTS zxevts = {0};

ZXNSO( evt )
{
  zxEvtPtr const events[ zxEVT_COUNT ];
  ZXV_DEC_BODY( zxEVENTS, zxEVTPTR );
  bool (*addEvent)( zxEVENTS *events, zxEVTPTR event );
  void (*remEvent)( zxEVENTS *events, zxEVTPTR event );
} zxn_evt;

static zxn_evt const zxevt = 
{
  {
    zxEVENT_onIdle,
    zxEVENT_onInit,
    zxEVENT_onKill,
    zxEVENT_onChar,
    zxEVENT_onKeyD,
    zxEVENT_onKeyU,
    zxEVENT_onCurMV,
    zxEVENT_onCurLD,
    zxEVENT_onCurMD,
    zxEVENT_onCurRD,
    zxEVENT_onCurBD,
    zxEVENT_onCurLU,
    zxEVENT_onCurMU,
    zxEVENT_onCurRU,
    zxEVENT_onCurBU,
    zxEVENT_onCurWH,
    zxEVENT_onFocus,
    zxEVENT_onBlur,
    zxEVENT_onShow,
    zxEVENT_onHide,
    zxEVENT_onMax,
    zxEVENT_onMin,
    zxEVENT_onRes,
    zxEVENT_onShowAct,
    zxEVENT_onHideAct,
    zxEVENT_onMaxAct,
    zxEVENT_onMinAct,
    zxEVENT_onResAct,
    zxEVENT_onShowNoa,
    zxEVENT_onHideNoa,
    zxEVENT_onMaxNoa,
    zxEVENT_onMinNoa,
    zxEVENT_onResNoa,
    zxEVENT_onOpen,
    zxEVENT_onShut,
    zxEVENT_onQuit
  },
  ZXV_DEF_BODY( zxEVENTS, {0} ),
  zxEVENTS_addEvent,
  zxEVENTS_remEvent
};

#endif