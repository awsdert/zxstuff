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
  zxapp_main(
    zxHwnd     rootWH,
    zxInstance prevI,
    zxInstance thisI,
    zxTEXT     *args );
ZXSYS zxTEXT const* zxapp_getTitle( void );
ZXSYS void zxapp_setTitle( zxTEXT const *txt );

typedef struct zxapp_struct
{
#ifdef ZXCONSOLE
  int (*_main)( char** args, char* );
#else
  int (*_main)(
    zxHwnd     rootWH,
    zxInstance prevI,
    zxInstance thisI,
    zxTEXT     *args );
#endif
} zxapp;

ZXC_SHUT

#endif