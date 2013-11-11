#include "app.h"
#include "obj.h"

#pragma once
#ifndef ZX_EVENT_H
#define ZX_EVENT_H

#if ZXMSW
ZXSYS LRESULT CALLBACK
  zxEVENT_onEvent( HWND wh, UINT msg, WPARAM wp, LPARAM lp );
#else
ZXSYS zxsl __stdcall
  zxEVENT_onEvent( zxHwnd wh, zxul msg, zxul *wp, zxul *lp );
#endif

typedef enum zxEVT_enum
{
  zxEVT_IDLE = 0u,
  zxEVT_INIT,
  zxEVT_KILL,
  zxEVT_CMD,
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
  zxEVT_ACTIVATE,
  zxEVT_DISIVATE,
  zxEVT_ENABLE,
  zxEVT_DISABLE,
  zxEVT_CREATE,
  zxEVT_DESTROY,
  zxEVT_QUIT,
  zxEVT_PAINT,
  zxEVT_PAINTNC,
  zxEVT_COUNT
} zxEVT;



typedef struct zxEVENT_struct
{
  zxOBJ  m_obj;
  zxHwnd m_wh;
  zxEVT  m_evt;
  void*  m_ptr;
  zxul   m_ptrType; /* 0 if zxWINDOW */
  bool   m_stopEvent;
#if ZXMSW
  UINT   m_mswMsg;
  WPARAM m_mswWP;
  LPARAM m_mswLP;
#endif
} zxEVENT;

#define ZXEVENT( FUN ) zxsl FUN( zxEVENT *event )
typedef ZXEVENT( (*zxEvtPtr) );

typedef struct zxEVTPTR_struct
{
  zxEVT    type;
  zxEvtPtr proc;
} zxEVTPTR;

ZXV_OBJ( zxEVENTS, zxEVTPTR );

ZXV_DEC( zxEVENTS, zxEVTPTR, ZXSYS );

/*
  These are not meant to be used in regular code;
  Create functions for the object holding an
  events object so that it may call these.
*/

ZXSYS bool zxEVENTS_addEvent( zxEVENTS* events, zxEVTPTR event );
ZXSYS void zxEVENTS_remEvent( zxEVENTS* events, zxEVTPTR event );
ZXSYS zxEVENTS* zxEVENTS_getDefEvents( void );

ZXSYS ZXEVENT( zxEVENT_onIdle  );
ZXSYS ZXEVENT( zxEVENT_onInit  );
ZXSYS ZXEVENT( zxEVENT_onKill  );
ZXSYS ZXEVENT( zxEVENT_onCmd   );
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
ZXSYS ZXEVENT( zxEVENT_onActivate );
ZXSYS ZXEVENT( zxEVENT_onDisivate );
ZXSYS ZXEVENT( zxEVENT_onEnable  );
ZXSYS ZXEVENT( zxEVENT_onDisable  );
ZXSYS ZXEVENT( zxEVENT_onCreate );
ZXSYS ZXEVENT( zxEVENT_onDestroy );
ZXSYS ZXEVENT( zxEVENT_onQuit );
ZXSYS ZXEVENT( zxEVENT_onPaint );
ZXSYS ZXEVENT( zxEVENT_onPaintNC );

ZXNSO( evt )
{
  zxEvtPtr const events[ zxEVT_COUNT ];
  ZXV_NS_DEC( zxEVENTS, zxEVTPTR );
  bool (*addEvent)( zxEVENTS *events, zxEVTPTR event );
  void (*remEvent)( zxEVENTS *events, zxEVTPTR event );
  zxEVENTS* (*getDefEvents)( void );
#if ZXMSW
  LRESULT (CALLBACK *onEvent)( HWND wh, UINT msg, WPARAM wp, LPARAM lp );
#else
  zxsl    (__stdcall *onEvent)( zxHwnd wh, zxul msg, zxul* wp, zxul* lp );
#endif
} zxn_evt;

static zxn_evt const zxevt =
{
  {
    zxEVENT_onIdle,
    zxEVENT_onInit,
    zxEVENT_onKill,
    zxEVENT_onCmd,
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
    zxEVENT_onActivate,
    zxEVENT_onDisivate,
    zxEVENT_onEnable,
    zxEVENT_onDisable,
    zxEVENT_onCreate,
    zxEVENT_onDestroy,
    zxEVENT_onQuit,
    zxEVENT_onPaint,
    zxEVENT_onPaintNC
  },
  ZXV_NS_DEF( zxEVENTS, {0} ),
  zxEVENTS_addEvent,
  zxEVENTS_remEvent,
  zxEVENTS_getDefEvents,
  zxEVENT_onEvent
};

#endif
