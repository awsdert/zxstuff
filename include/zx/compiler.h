#ifndef ZX_COMPILER_H
#define ZX_COMPILER_H

#ifdef __STDC_VERSION__
#define ZXC __STDC_VERSION__
#else
#define ZXC 198900
#endif

#ifdef __cplusplus
#define ZXCPP __cplusplus
#define ZXC_EXT  extern "C"
#define ZXC_SHUT }
#define ZXC_OPEN extern "C" {
#else
#define ZXCPP 0
#define ZXC_EXT
#define ZXC_SHUT
#define ZXC_OPEN
#endif

#if defined( __DEBUG ) || defined( _DEBUG ) || defined( DEBUG )
#define ZXDBG 1
#else
#define ZXDBG 0
#endif

#if defined( __UNICODE ) || defined( _UNICODE ) || defined( UNICODE )
#define ZXUNICODE 1
#else
#define ZXUNICODE 0
#endif

#ifdef _MSC_VER
#define ZX_MSC_VER _MSC_VER
#else
#define ZX_MSC_VER 0
#endif

#ifdef __attribute__
#define ZX_GNU_VER 1
#define ZXATTR( ATTR ) __attribute__((ATTR))
#else
#define ZX_GNU_VER 0
#define ZXATTR( ATTR )
#endif

#if ZX_MSC_VER
#define ZXMSG( m_txt ) message( m_txt )
#define ZX_OTHER_VER 0
#elif ZX_GNU_VER
#define ZXMSG( m_txt ) message m_txt
#define ZX_OTHER_VER 0
#else
#define ZXMSG( m_txt ) m_txt
#define ZX_OTHER_VER 1
#endif

#define ZXUNUSED  ZXATTR( __unused__     )
#define ZXSTDCALL ZXATTR( __stdcall__    )
#define ZXCDEC    ZXATTR( __cdec__       )
#define ZXDEPREC  ZXATTR( __deprecated__ )
#define ZXNOTHROW ZXATTR( __nothrow__    )

#if ZXDBG
#if ZXC
#include <assert.h>
#else
#include <cassert>
#endif
#else
#define assert( _Expression )
#endif

#if ZXCPP || ZXC >= 199900 || defined( ZXPREC_GNU )
#define ZXILL long long
#define ZXLL( VAL ) VAL##LL
#elif ZX_MSC_VER >= 800
#define ZXLL( VAL ) VAL##i64
#define ZXILL __int64
#else
#define ZXLL( VAL ) VAL
#endif

#ifdef ZXILL
typedef          ZXILL zxill;
typedef unsigned ZXILL zxull;
typedef   signed ZXILL zxsll;
#endif

#define ZXB1  ZXLL( 1 )
#define ZXB1U ZXLL( 1U )

typedef unsigned char  zxuc;
typedef   signed char  zxsc;
typedef unsigned short zxus;
typedef   signed short zxss;
typedef unsigned long  zxul;
typedef   signed long  zxsl;
typedef unsigned int   zxui;
typedef   signed int   zxsi;

#if ZXC >= 198900 || defined( _MSC_EXTENSIONS )
#define ZXVP void*
#else
#define ZXVP zxuc*
#endif

typedef ZXVP zxvp;

#endif
