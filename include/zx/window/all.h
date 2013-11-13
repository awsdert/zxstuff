#pragma once
#include "../event.h"

#ifndef ZXWIN_ALL_H
#define ZXWIN_ALL_H

ZXC_OPEN

typedef enum zxWIN_enum
{
  zxWIN_NULL = 0u,
  zxWIN_FRAME,
  zxWIN_TBOX,
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

typedef struct { int ignored; } zxWC;
typedef struct { int ignored; } zxWCX;
#endif

ZXC_SHUT

#endif
