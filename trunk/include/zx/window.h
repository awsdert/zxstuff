#include "std/text.h"
#include "window/msw.h"

#ifndef ZXWINDOW_H
#define ZXWINDOW_H

ZXC_OPEN

typedef struct zxoWINDOW_struct
{
  size_t   m_id;
  zxWIN    m_win;
  zxsi     m_x, m_y, m_w, m_h;
  zxTEXT   m_title;
  /* System Specfic */
  zxWndClass   *m_wc;
  zxWndClassEx *m_wcx;
  zxHandle      m_hdl;
} zxoWINDOW;

typedef struct zxEVENT_struct
{
  zxEVT     m_type;
#if ZXMSW
  HWND      m_mswHwnd;
  UINT      m_mswMsg;
  WPARAM    m_mswWP;
  LPARAM    m_mswLP;
#endif
} zxEVENT;

zxEvtCBR zxv_zxWINDOW_onFocus( zxoWINDOW* win, zxEVENT* event );
zxEvtCBR zxv_zxWINDOW_onBlur(  zxoWINDOW* win, zxEVENT* event );
zxEvtCBR zxv_zxWINDOW_onChar(  zxoWINDOW* win, zxEVENT* event );
zxEvtCBR zxv_zxWINDOW_onKeyD(  zxoWINDOW* win, zxEVENT* event );
zxEvtCBR zxv_zxWINDOW_onKeyP(  zxoWINDOW* win, zxEVENT* event );
zxEvtCBR zxv_zxWINDOW_onKeyU(  zxoWINDOW* win, zxEVENT* event );

typedef struct zxEVENTS_struct
{
  zxEvtCBR (*onFocus)( zxoWINDOW* win, zxEVENT* event );
  zxEvtCBR (*onBlur)(  zxoWINDOW* win, zxEVENT* event );
  zxEvtCBR (*onChar)(  zxoWINDOW* win, zxEVENT* event );
  zxEvtCBR (*onKeyD)(  zxoWINDOW* win, zxEVENT* event );
  zxEvtCBR (*onKeyP)(  zxoWINDOW* win, zxEVENT* event );
  zxEvtCBR (*onKeyU)(  zxoWINDOW* win, zxEVENT* event );
} zxEVENTS;

ZXV_DEC_1ST( zxWINDOW )
{
  zxEVENTS   m_events;
  zxoWINDOW *m_core;
  zxv_zxWINDOW_struct
    *m_base;
  zxVECTOR m_kids;
} zxWINDOW;

ZXV_DEC_2ND( zxWINDOW, zxWINDOW* );

typedef struct zxn_w_struct
{
  ZXV_DEC_BODY( zxWINDOW, zxWINDOW* );
  zxEVENTS defEvents;
} zxn_w;

ZXSYS zxsi zxmain(
             zxHandle   rootWH,
             zxInstance prevI,
             zxInstance thisI,
             zxTEXT*    args );

ZXSYS zxInstance
  zxGetPrevI( void );
ZXSYS zxInstance
  zxGetThisI( void );
ZXSYS zxWINDOW*
  zxo_zxWINDOW__init( zxoWINDOW* core );
ZXSYS zxWINDOW*
  zxo_zxWINDOW__kill( zxWINDOW*  win, bool delKids );
ZXSYS zxHandle
  zxo_zxWINDOW_getHandle( size_t id );
ZXSYS zxWINDOW*
  zxo_zxWINDOW_getWindow( size_t id );
ZXSYS zxVECTOR*
  zxo_zxWINDOW_allWindows( void );
ZXSYS zxWINDOW*
  zxo_zxWINDOW_byHandle( zxHandle wh );
#define ZXONEWWINDOW (zxoWINDOW*)malloc( sizeof( zxoWINDOW ) )
#define ZXFREE( PTR ) free( PTR ); PTR = NULL

ZXSYS int zx_mswNewWindow(
  zxWINDOW *kid,
  zxul      style,
  zxul      ext );

ZXSYS zxWINDOW*  zxNewWINDOW( zxWINDOW *parent );
ZXSYS zxWINDOW*  zxGetWindowH( zxHandle hdl );

ZXSYS zxui       zx_ResizeWindows( zxuint initLength );
ZXSYS void       zx_SetAllWindows( zxWINDOW** newArray );
/**
  @param returnCode The value you want returned after
**/
ZXSYS int        zxFreeWindows( int returnCode );
ZXSYS void       zx_SetWindowCount( zxuint newCount );
ZXSYS void       zx_InitWINDOW( zxWINDOW *win );

ZXSYS void zxInitWndClass(   zxWndClass   *wc );
ZXSYS void zxInitWndClassEx( zxWndClassEx *wcx );

static zxWndClass   ZXUNUSED( zx_WC )[  zxWIN_COUNT ];
static zxWndClassEx ZXUNUSED( zx_WCX )[ zxWIN_COUNT ];

ZXSYS void zx_InitWC( void );
ZXSYS void zx_FreeWC( void );

ZXC_SHUT

#endif
