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

#define zxDefWinEvt DefWindowProc( win->m_hdl, event->mswMsg, event->mswWP, event->mswLP )
#define zxEvtCBR LRESULT
typedef HINSTANCE  zxInstance;
typedef HWND       zxHandle;
typedef WNDCLASS   zxWndClass;
typedef WNDCLASSEX zxWndClassEx;
ZXSYS LRESULT CALLBACK zx_mswEvent( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam );

static ATOM ZXUNUSED( zx_mswATOM )[  zxWIN_COUNT ];
static ATOM ZXUNUSED( zx_mswATOMX )[ zxWIN_COUNT ];
ZXSYS void zx_mswInitATOM( void );
ZXSYS void zx_mswFreeATOM( void );

ZXSYS zxuint zx_mswSetText( HWND hdl, zxTEXT* text, zxuint line, zxuint pos, HBRUSH bg );
ZXSYS zxuint zx_mswSetCaret( HWND hdl, zxuint line, zxuint pos );

ZXC_SHUT

#define ZXWINDOW_MSW_H
#endif
#endif
