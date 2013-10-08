#include "all.h"

#if ZXMSW
#include <commctrl.h>
#ifndef ZXWINDOW_MSW_H

ZXC_OPEN

typedef struct zxFONT_struct
{
  UINT    m_style;
  int     m_weight;
  int     m_w, m_h;
  zxTEXT *m_family;
} zxFONT;

#define zxDefWinEvt DefWindowProc( \
  win->m_hdl, event->m_mswMsg, event->m_mswWP, event->m_mswLP )
#define zxEvtCBR LRESULT
typedef HINSTANCE  zxInstance;
typedef HWND       zxHandle;
typedef WNDCLASS   zxWndClass;
typedef WNDCLASSEX zxWndClassEx;
ZXSYS LRESULT CALLBACK zx_mswEvent(
  HWND hWnd,
  UINT msg,
  WPARAM wParam,
  LPARAM lParam );

static ATOM ZXUNUSED( zx_mswATOM )[  zxWIN_COUNT ];
static ATOM ZXUNUSED( zx_mswATOMX )[ zxWIN_COUNT ];
ZXSYS void zx_mswInitATOM( void );
ZXSYS void zx_mswFreeATOM( void );

ZXSYS zxui zx_mswSetText(
  HWND   wh,
  zxTEXT *txt,
  int    line,
  int    pos,
  HBRUSH bg );

ZXSYS zxui zx_mswSetCaret( HWND hdl, int line, int pos );

ZXC_SHUT

#define ZXWINDOW_MSW_H
#endif
#endif
