#pragma once
#ifndef ZXAPP_H
#define ZXAPP_H
#include "obj.h"

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
ZXSYS int ZXSYS_CALL zxapp__main( int argc, zxch *argv[] );
#else
ZXSYS int ZXSYS_CALL
  zxapp__main(
    zxInstance prevI,
    zxInstance thisI,
    LPSTR      cmdl,
    int        showAs );
#endif
ZXSYS zxTEXT* ZXSYS_CALL zxapp_getTitle( void );
ZXSYS void    ZXSYS_CALL zxapp_setTitle( zxch const *txt );

ZXNSO( app )
{
#ifdef ZXCONSOLE
  int (ZXSYS_CALL *_main)( int argc, zxch *argv[] );
#else
  int (ZXSYS_CALL *_main)(
    zxInstance thisI,
    zxInstance prevI,
    LPSTR      cmdl,
    int        showAs );
#endif
  zxTEXT* (ZXSYS_CALL *getTitle)( void );
  void    (ZXSYS_CALL *setTitle)( zxch const *txt );
} zxn_app;

static zxn_app zxapp =
{
  zxapp__main,
  zxapp_getTitle,
  zxapp_setTitle
};

ZXC_SHUT

#endif
