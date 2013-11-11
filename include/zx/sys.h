#include "compiler.h"
#include "std/arch.h"

#pragma once
#ifndef ZXDLL_EXP

ZXC_OPEN

#define ZXMSW 0
#define ZXALL 0

#if   defined( __WIN64 ) || defined( _WIN64 ) || defined( WIN64 )
#undef ZXMSW
#define ZXMSW 64
#elif defined( __WIN32 ) || defined( _WIN32 ) || defined( WIN32 )
#undef ZXMSW
#define ZXMSW 32
#elif defined( __WINDOWS ) || defined( _WINDOWS ) || defined( WINDOWS )
#undef ZXMSW
#define ZXMSW 16
#else
#undef  ZXALL
#define ZXALL 32
#endif

#if defined( __CONSOLE ) || defined( _CONSOLE ) || defined( CONSOLE )
#define ZXCONSOLE
#endif

#if ZXMSW

#include <wchar.h>
#include <windows.h>

#define ZXDLL_EXP __declspec(dllexport)
#define ZXDLL_IMP __declspec(dllimport)

#else

#ifndef NULL
#if ZXCPP
#define NULL 0
#else
#define NULL (void*)0
#endif
#endif

typedef int BOOL;

#ifndef TRUE
#define TRUE  1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#define ZXDLL_EXP
#define ZXDLL_IMP

#endif

ZXC_SHUT
#endif

