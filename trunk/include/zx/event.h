#pragma once
#ifndef ZXEVT_H
#define ZXEVT_H
#include "event/all.h"
#include "event/msw.h"

ZXC_OPEN

typedef struct zxEVENT_struct
{
  zxHwnd  m_wh;
  size_t  m_wid;
  zxMSG   m_msg;
  zxOBJ   m_obj;
  bool    m_stopEvent;
  long    m_wp, m_lp;
} zxEVENT;

#define ZX_EVENT( FUN ) zxsl FUN( zxEVENT *event )
#define ZXEVENT( FUN ) ZX_EVENT( __stdcall FUN )
typedef ZX_EVENT( (__stdcall *zxEvtPtr) );

typedef struct zxEVT_struct
{
  size_t   wid, oid, t, subType;
  zxMSG    msg;
  zxEvtPtr proc;
} zxEVT;

ZXV_OBJ( zxvEVT, zxEVT );

ZXNSO( evt )
{
  ZXV_NS_DEC( zxvEVT, zxEVT, ZXSYS_CALL );
#if ZXMSW
  LRESULT (CALLBACK  *onEvent)( HWND wh, UINT msg, WPARAM wp, LPARAM lp );
#else
  zxsl    (__stdcall *onEvent)( zxHwnd wh, zxul msg, zxul* wp, zxul* lp );
#endif
} zxn_evt;

extern zxn_evt const zxevt;

typedef struct zxWH_struct
{
  zxHwnd   wh;
  size_t   wid;
  zxOBJ    win;
  zxEvtPtr onEvent;
  zxvSIZE  objs;
} zxWH;

ZXV_OBJ( zxvWH, zxWH );

ZXNSO( wh )
{
  zxWH const defWH;
  ZXV_NS_DEC( zxvWH, zxWH, ZXSYS_CALL );
  zxvWH* (ZXSYS_CALL *all)( void );
  zxWH*  (ZXSYS_CALL *byHwnd)( zxHwnd wh );
  zxWH*  (ZXSYS_CALL *byId)( size_t wid );
} zxn_wh;

extern zxn_wh const zxwh;

ZXC_SHUT

#endif
