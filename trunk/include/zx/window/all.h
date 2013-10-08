#include "../std/text.h"
#ifndef ZXWINDOW_ALL_H
#define ZXWINDOW_ALL_H

ZXC_OPEN

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

ZXSYS zxTEXT const* zxGetAppTitle( void );
ZXSYS void zxSetAppTitle( zxTEXT const *txt );

typedef enum zxWIN_enum
{
  zxWIN_NULL = 0u,
  zxWIN_FRAME,
  zxWIN_TEXTBOX,
  zxWIN_COUNT
} zxWIN;

#if ZXALL
typedef struct zxFONT_struct
{
  zxui  m_style;
  zxui  m_weight;
  zxui  m_w, m_h;
  zxch *m_family;
} zxFONT;

#define zxEvtCBR long
typedef void* zxInstance;
#define zxDefWinEvt 0
typedef ZXVP zxHandle;
typedef struct { int ignored; } zxWndClass;
typedef struct { int ignored; } zxWndClassEx;
#endif

ZXC_SHUT

#endif
