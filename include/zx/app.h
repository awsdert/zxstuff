#include "std/text.h"

#pragma once
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

#ifdef ZXCONSOLE
ZXSYS int zxapp__main( int argc, zxch *argv[] );
#else
ZXSYS int
  zxapp__main(
    zxInstance prevI,
    zxInstance thisI,
    LPSTR      cmdl,
    int        showAs );
#endif
ZXSYS zxTEXT const* zxapp_getTitle( void );
ZXSYS void zxapp_setTitle( zxTEXT const *txt );

typedef struct zxn_app_struct
{
#ifdef ZXCONSOLE
  int (*_main)( int argc, zxch *argv[] );
#else
  int (*_main)(
    zxInstance thisI,
    zxInstance prevI,
    LPSTR      cmdl,
    int        showAs );
#endif
} zxn_app;

static zxn_app zxapp =
{
  zxapp__main
};

ZXC_SHUT

#endif
