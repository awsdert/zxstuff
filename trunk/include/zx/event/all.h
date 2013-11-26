#pragma once
#ifndef ZX_EVT_ALL_H
#define ZX_EVT_ALL_H
#include "../app.h"

#if ZXALL

ZXC_OPEN


/* Window Messages */
#define ZXWM_CREATE     0x1
#define ZXWM_DESTROY    0x2
#define ZXWM_FOCUS      0x7
#define ZXWM_BLUR       0x8
#define ZXWM_QUIT       0x9
#define ZXWM_CMD        0x11
#define ZXWM_KEYD       0x100
#define ZXWM_KEYU       0x101
#define ZXWM_CHAR       0x102
#define ZXWM_DEAD       0x103
#define ZXWM_WIDE       0x109
#define ZXWM_CURMV      0x200
#define ZXWM_CURLD      0x201
#define ZXWM_CURLU      0x202
#define ZXWM_APPCMD     0x319

/* Edit Control Messages */
#define ZXEM_CHANGE     0x10000
#define ZXEM_FOCUS      0x20000

typedef zxul zxMSG;

ZXSYS zxsl __stdcall
  zxEVENT_onEvent( zxHwnd wh, zxul msg, zxul *wp, zxul *lp );

ZXC_SHUT

#endif

#endif
