#pragma once
#include "all.h"

#if ZXMSW
#include <commctrl.h>

#ifndef ZX_WINDOW_MSW_H
#define ZX_WINDOW_MSW_H

ZXC_OPEN

typedef struct zxFONT_struct
{
  UINT    m_style;
  int     m_weight;
  int     m_w, m_h;
  zxTEXT *m_family;
} zxFONT;

typedef WNDCLASS   zxWC;
typedef WNDCLASSEX zxWCX;

ZXC_SHUT

#endif

#endif
