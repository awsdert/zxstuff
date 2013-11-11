#include <stddef.h>

#pragma once
#ifndef ZX_STDC_H
#define ZX_STDC_H

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

#ifdef __OBJC__
#define ZXOBJC 1
#else
#define ZXOBJC 0
#endif

#define ZXCSHARP 0

#ifdef _MSC_VER
#define ZX_MSC _MSC_VER
#else
#define ZX_MSC 0
#endif

#ifdef __GNUC__
#ifndef __GNUC_PATCHLEVEL__
#define __GNUC_PATCHLEVEL__ 0
#endif
#define ZX_GCC ( __GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__ )
#else
#define ZX_GCC 0
#endif

#ifdef __GNUG__
#ifndef __GNUG_PATCHLEVEL__
#define __GNUG_PATCHLEVEL__ 0
#endif
#define ZX_GPP ( __GNUG__ * 10000 + __GNUG_MINOR__ * 100 + __GNUG_PATCHLEVEL__ )
#else
#define ZX_GPP 0
#endif

#if defined( _DLL ) || defined( _WINDLL )
#define ZXDLL 1
#else
#define ZXDLL 0
#endif

#ifdef __STRICT_ANSI__
#define ZXANSI 1
#else
#define ZXANSI 0
#endif

#ifdef __STDC_VERSION__
#define ZXSTDC __STDC_VERSION__
#elif ZXCPP || ZXOBJC || defined(__STDC__) || ZX_MSC || ZX_GCC || ZX_GPP
#define ZXSTDC 198901L
#else
#define ZXSTDC 0
#error Need C89 support at minimum
#endif

#if defined( _DEBUG ) || defined( DEBUG ) || defined( NDEBUG  )
#define ZXDBG 1
#else
#define ZXDBG 0
#endif

#if ZXDBG
#if ZXCPP
#include <cassert>
#else
#include <assert.h>
#endif
#define ZXASSERT( EXP ) if ( EXP ) assert( EXP ); if ( EXP )
#else
#define ZXASSERT( EXP ) if ( EXP )
#endif

#if defined( _UNICODE ) || defined( UNICODE )
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
