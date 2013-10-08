#include "std/text.h"

#if ZXMSW
#include "window/msw.h"
#else
#include "window/all.h"
#endif

#ifndef ZXWINDOW_H
ZXC_OPEN

typedef struct zxEVENT_struct
{
  zxEVT evtType;
#if ZXMSW
  HWND   mswHwnd;
  UINT   mswMsg;
  WPARAM mswWP;
  LPARAM mswLP;
#endif
} zxEVENT;

ZXSYS zxInstance zxGetPrevI( void );
ZXSYS zxInstance zxGetThisI( void );
ZXSYS void zx_SetPrevI( zxInstance i );
ZXSYS void zx_SetThisI( zxInstance i );

typedef struct zxWINDOW_struct
{
  struct zxWINDOW_struct*  m_parent;
  struct zxWINDOW_struct** m_kids;
  zxuint        m_kidsCount;
  zxuint        m_id;
  zxWIN         m_winType;
  int           m_x, m_y, m_w, m_h;
  /* System Specfic */
  zxWndClass   *m_wc;
  zxWndClassEx *m_wcx;
  zxHandle      m_hdl;
/* Not for application development, is for default handlers */
  zxEvtCBR    (*m_onFocus)( struct zxWINDOW_struct* win, zxEVENT* event );
  zxEvtCBR    (*m_onBlur)( struct zxWINDOW_struct* win, zxEVENT* event );
  zxEvtCBR    (*m_onChar)( struct zxWINDOW_struct* win, zxEVENT* event );
  zxEvtCBR    (*m_onKeyD)( struct zxWINDOW_struct* win, zxEVENT* event );
  zxEvtCBR    (*m_onKeyP)( struct zxWINDOW_struct* win, zxEVENT* event );
  zxEvtCBR    (*m_onKeyU)( struct zxWINDOW_struct* win, zxEVENT* event );
} zxWINDOW;

ZXSYS int zx_NewWindow( zxTEXT text, zxWINDOW* kid, zxul style, zxul ext );

ZXSYS zxWINDOW*  zxNewWINDOW( void );
ZXSYS zxWINDOW*  zxGetWindowH( zxHandle hdl );
ZXSYS zxWINDOW** zxGetAllWindows( void );
ZXSYS zxuint     zxGetWindowCount( void );
ZXSYS zxuint     zx_ResizeWindows( zxuint initLength );
ZXSYS void       zx_SetAllWindows( zxWINDOW** newArray );
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
/*
  returnCode is merely for smaller code,
  if you don't need it then set it to whatever you want as it is unused
*/

ZXC_SHUT
#define zxWINDOW_H
#endif
