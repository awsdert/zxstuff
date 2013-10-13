#include "app.h"

#ifndef ZX_EVENT_H
#define ZX_EVENT_H

typedef enum zxEVT_enum
{
  zxEVT_NULL = 0u,
  zxEVT_KEYU,
  zxEVT_KEYP,
  zxEVT_KEYD,
  zxEVT_CURMV,
  zxEVT_CURLC,
  zxEVT_CURMC,
  zxEVT_CURRC,
  zxEVT_CURWH,
  zxEVT_WIN_FOCUS,
  zxEVT_WIN_BLUR,
  zxEVT_WIN_OPEN,
  zxEVT_WIN_SHUT,
  zxEVT_WIN_QUIT,
  zxEVT_COUNT
} zxEVT;

typedef struct zxEVENT_struct
{
  zxHwnd m_wh;
  zxEVT  m_evt;
  void*  m_ptr;
  zxul   m_ptrType; /* 0 if zxWINDOW */
#if ZXMSW
  UINT   m_mswMsg;
  WPARAM m_mswWP;
  LPARAM m_mswLP;
#endif
} zxEVENT;

#define ZXEVENT( NAME ) zxEvtCBR NAME##( zxEVENT* event )
typedef ZXEVENT( (*zxEvtPtr) );

typedef struct zxEVENTS_struct
{
  zxVECTOR  m_data;
  zxEvtPtr* m_evts;
} zxEVENTS;

ZXEVENT( zxroot_onFocus );
ZXEVENT( zxroot_onBlur  );
ZXEVENT( zxroot_onChar  );
ZXEVENT( zxroot_onKeyD  );
ZXEVENT( zxroot_onKeyP  );
ZXEVENT( zxroot_onKeyU  );

static zxEvtPtrs *zxroot_events =
{
  zxroot_onFocus,
  zxroot_onBlur,
  zxroot_onChar,
  zxroot_onKeyD,
  zxroot_onKeyP,
  zxroot_onKeyU
};

ZXSYS bool zxAddEvent( zxEVENTS* events, zxEvtPtr event );
ZXSYS void zxRemEvent( zxEVENTS* events, zxEvtPtr event );

#if ZXMSW
#define zxDefWinEvt DefWindowProc( \
  win->m_hdl, event->m_mswMsg, event->m_mswWP, event->m_mswLP )
#define zxEvtCBR    LRESULT
ZXSYS zxEvtCBR CALLBACK
  zx_mswEvent( zxHwnd wh, UINT msg, WPARAM wp, LPARAM lp );
#else
#define zxDefWinEvt 0
#define zxEvtCBR    zxsi
ZXSYS zxEvtCBR __stdcall
  zx_mswEvent( zxHwnd wh, zxul msg, zxul *wp, long *lp );
#endif

#endif