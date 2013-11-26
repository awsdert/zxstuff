#pragma once
#ifndef ZX_EVT_MSW_H
#define ZX_EVT_MSW_H
#include "all.h"

#if ZXMSW

ZXC_OPEN

#define ZXWM_CREATE     WM_CREATE
#define ZXWM_DESTROY    WM_DESTROY
#define ZXWM_FOCUS      WM_SETFOCUS
#define ZXWM_BLUR       WM_KILLFOCUS
#define ZXWM_QUIT       WM_QUIT
#define ZXWM_CMD        WM_COMMAND
#define ZXWM_KEYD       WM_KEYDOWN
#define ZXWM_KEYU       WM_KEYUP
#define ZXWM_CHAR       WM_CHAR
#define ZXWM_DEAD       WM_DEADCHAR
#define ZXWM_WIDE       WM_UNICHAR
#define ZXWM_CURMV      WM_MOUSEMOVE
#define ZXWM_CURLD      WM_LBUTTONDOWN
#define ZXWM_CURLU      WM_LBUTTONUP
#define ZXEM_CHANGE     EM_CHANGE
#define ZXEM_FOCUS      EM_SETFOCUS
#define ZXWM_APPCMD     WM_APPCOMMAND

typedef UINT zxMSG;

ZXSYS LRESULT CALLBACK
  zxEVENT_onEvent( HWND wh, UINT msg, WPARAM wp, LPARAM lp );

ZXC_SHUT

#endif

#endif
