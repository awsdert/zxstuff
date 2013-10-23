#pragma once
#include "compiler.h"
#include "std/arch.h"
#ifndef ZXSYS_H

ZXC_OPEN

#define ZXMSW 0
#define ZXALL 0

#if defined( ZX_MSW )

#undef ZXMSW
#if   defined( __WIN64 ) || defined( _WIN64 ) || defined( WIN64 )
#define ZXMSW 64
#elif defined( __WIN32 ) || defined( _WIN32 ) || defined( WIN32 )
#define ZXMSW 32
#else
#define ZXMSW 16
#endif

#else
#undef  ZXALL
#define ZXALL 1
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
#define NULL (ZXVP)0
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

#define ZXSYS_H
#endif

