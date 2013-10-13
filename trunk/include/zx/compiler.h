#include "stdc.h"
#ifndef ZX_COMPILER_H
#define ZX_COMPILER_H

#if defined( _DLL ) || defined( _WINDLL )
#define ZXDLL 1
#else
#define ZXDLL 0
#endif

#ifdef _MSC_VER
#define ZX_MSC_VER _MSC_VER
#else
#define ZX_MSC_VER 0
#endif

#ifdef __attribute__
#define ZX_GNU_VER __VERSION__
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

#if ZXCPP || ZXC >= 199900L || defined( ZXPREC_GNU )
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

#endif
