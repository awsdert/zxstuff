#pragma once
#include <stddef.h>
#ifndef ZX_STDC_H
#define ZX_STDC_H

#ifdef __STDC_VERSION__
#define ZXSTDC __STDC_VERSION__
#elif defined(__STDC__) || defined( _MSC_EXTENSIONS )
#define ZXSTDC 198901L
#else
#define ZXSTDC 0
#endif

#ifdef __OBJC__
#define ZXOBJC 1
#else
#define ZXOBJC 0
#endif

#ifdef __cplusplus
#define ZXCPP __cplusplus
#define ZXC_SHUT }
#define ZXC_OPEN extern "C" {
#define ZXC_EXT  extern "C"
#else
#define ZXCPP 0
#define ZXC_SHUT
#define ZXC_OPEN
#define ZXC_EXT
#endif

#if !ZXSTDC && !ZXCPP && !ZXOBJC
#error Your compiler is too old
#endif

#if defined( __DEBUG ) || defined( _DEBUG ) || defined( DEBUG )
#define ZXDBG 1
#else
#define ZXDBG 0
#endif

#if ZXDBG
#if ZXC
#include <assert.h>
#else
#include <cassert>
#endif
#define ZXASSERT( EXP ) if ( EXP ) assert( EXP ); if ( EXP )
#else
#define ZXASSERT( EXP ) if ( EXP )
#endif

#if defined( __UNICODE ) || defined( _UNICODE ) || defined( UNICODE )
#define ZXUNICODE 1
#else
#define ZXUNICODE 0
#endif

#if defined( __CHAR_UNSIGNED__ )
#define ZXUCHAR 1
#else
#define ZXUCHAR 0
#endif

#if defined( __WIDE_UNSIGNED__ )
#define ZXUWIDE 1
#else
#define ZXUWIDE 0
#endif

typedef unsigned char  zxuc;
typedef   signed char  zxsc;
typedef unsigned short zxus;
typedef   signed short zxss;
typedef unsigned long  zxul;
typedef   signed long  zxsl;
typedef unsigned int   zxui;
typedef   signed int   zxsi;

#endif