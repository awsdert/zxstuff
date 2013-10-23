#pragma once
#include "std/text.h"

#ifndef ZX_APP_H
#define ZX_APP_H

ZXC_OPEN

#if ZXMSW
typedef HANDLE    zxHandle;
typedef HWND      zxHwnd;
typedef HINSTANCE zxInstance;
#else
typedef void*     zxHandle;
typedef void*     zxHwnd;
typedef void*     zxInstance;
#endif

ZXSYS int
  zxapp__main(
    zxHwnd     rootWH,
    zxInstance prevI,
    zxInstance thisI,
    zxTEXT     *args );
ZXSYS zxTEXT const* zxapp_getTitle( void );
ZXSYS void zxapp_setTitle( zxTEXT const *txt );

typedef struct zxapp_struct
{
#ifdef ZXCONSOLE
  int (*_main)( int argc, char *argv[] );
#else
  int (*_main)(
    zxHwnd     rootWH,
    zxInstance thisI,
    zxInstance prevI,
    zxch       *cmdl,
    int        showAs );
#endif
} zxapp;

ZXC_SHUT

#endif