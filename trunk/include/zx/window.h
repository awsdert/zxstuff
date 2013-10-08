#include "std/text.h"
#include "window/msw.h"

#ifndef ZXWINDOW_H
#define ZXWINDOW_H

ZXC_OPEN

typedef struct zxEVENT_struct
{
  zxEVT m_type;
#if ZXMSW
  HWND   m_mswHwnd;
  UINT   m_mswMsg;
  WPARAM m_mswWP;
  LPARAM m_mswLP;
#endif
} zxEVENT;

ZXSYS zxInstance zxGetPrevI( void );
ZXSYS zxInstance zxGetThisI( void );
ZXSYS void zx_SetPrevI( zxInstance i );
ZXSYS void zx_SetThisI( zxInstance i );

#define zxWINDOW struct zxWINDOW_struct

zxWINDOW
{
  zxWINDOW*  m_parent;
  zxWINDOW** m_kids;
  zxuint        m_id;
  zxWIN         m_winType;
  int           m_x, m_y, m_w, m_h;
/* System Specfic */
  zxWndClass   *m_wc;
  zxWndClassEx *m_wcx;
  zxHandle      m_hdl;
/* Not for application development, is for default handlers */
  zxEvtCBR    (*m_onFocus)(
    zxWINDOW* win, zxEVENT* event );
  zxEvtCBR    (*m_onBlur)(
    zxWINDOW* win, zxEVENT* event );
  zxEvtCBR    (*m_onChar)(
    zxWINDOW* win, zxEVENT* event );
  zxEvtCBR    (*m_onKeyD)(
    zxWINDOW* win, zxEVENT* event );
  zxEvtCBR    (*m_onKeyP)(
    zxWINDOW* win, zxEVENT* event );
  zxEvtCBR    (*m_onKeyU)(
    zxWINDOW* win, zxEVENT* event );
};

ZXSYS int zx_NewWindow(
  zxTEXT   *txt,
  zxWINDOW *kid,
  zxul      style,
  zxul      ext );

ZXSYS zxWINDOW*  zxNewWINDOW( void );
ZXSYS zxWINDOW*  zxGetWindowH( zxHandle hdl );
ZXSYS zxWINDOW** zxGetAllWindows( void );
ZXSYS zxui       zxGetWindowCount( void );
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

zxEvtCBR zxOnChar( zxWINDOW* win, zxEVENT* event );
zxEvtCBR zxOnKeyD( zxWINDOW* win, zxEVENT* event );
zxEvtCBR zxOnKeyP( zxWINDOW* win, zxEVENT* event );
zxEvtCBR zxOnKeyU( zxWINDOW* win, zxEVENT* event );

ZXC_SHUT

#endif
