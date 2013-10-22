#pragma once
#include "../event.h"

#ifndef ZXWINDOW_ALL_H
#define ZXWINDOW_ALL_H

ZXC_OPEN

typedef enum zxWIN_enum
{
  zxWIN_NULL = 0u,
  zxWIN_FRAME,
  zxWIN_TEXTBOX,
  zxWIN_COUNT
#if ZXCPP
  ,zxWIN_CPP_NULL,
  zxWIN_CPP_FRAME,
  zxWIN_CPP_TEXTBOX,
  zxWIN_CPP_COUNT
#endif
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