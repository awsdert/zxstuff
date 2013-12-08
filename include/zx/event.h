#pragma once
#ifndef ZXEVT_H
#define ZXEVT_H
#include "event/all.h"
#include "event/msw.h"

ZXC_OPEN

typedef struct zxEVENT_struct
{
  zxHwnd  m_wh;
  zxui    m_wid;
  zxMSG   m_msg;
  zxus    m_cmd;
  zxOBJ   m_obj;
  bool    m_stopEvent;
  WPARAM  m_wp;
  LPARAM  m_lp;
} zxEVENT;

#define ZX_EVENT( FUN ) zxsl FUN( zxEVENT *event )
#define ZXEVENT( FUN ) ZX_EVENT( __stdcall FUN )
typedef ZX_EVENT( (__stdcall *zxEvtPtr) );

typedef struct zxEVT_struct
{
  zxui     wid, oid;
  size_t   type, subType;
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
  zxui     wid;
  zxOBJ    win;
  zxEvtPtr onEvent;
  zxvUI    objs;
} zxWH;

ZXV_OBJ( zxvWH, zxWH );

ZXNSO( wh )
{
  zxWH const defWH;
  ZXV_NS_DEC( zxvWH, zxWH, ZXSYS_CALL );
  zxvWH* (ZXSYS_CALL *all)( void );
  zxWH*  (ZXSYS_CALL *byHwnd)( zxHwnd wh );
  zxWH*  (ZXSYS_CALL *byId)( zxui wid );
} zxn_wh;

extern zxn_wh const zxwh;

ZXC_SHUT

#endif
