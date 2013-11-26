#pragma once
#ifndef ZX_COMPILER_H
#define ZX_COMPILER_H
#include "stdc.h"

#define ZXNSO( NAME ) typedef struct zxn_##NAME##_struct

#if ZX_GCC || ZX_GPP
#define ZXATTR( ATTR ) __attribute__((ATTR))
#else
#define ZXATTR( ATTR )
#endif

#define ZX_ASSTR( TXT ) #TXT
#define ZXASSTR( TXT ) ZX_ASSTR( TXT )
#define ZXTXT( TXT ) TXT

#if ZX_MSC
#define ZX_MSG( MSG ) ( ZXASSTR( MSG ) )
#else
#define ZX_MSG( MSG ) ZXASSTR( MSG )
#endif

#define ZXMSG( MSG ) ZX_MSG( MSG )

#define ZXUNUSED  ZXATTR( __unused__     )
#define ZXSTDCALL ZXATTR( __stdcall__    )
#define ZXCDEC    ZXATTR( __cdec__       )
#define ZXDEPREC  ZXATTR( __deprecated__ )
#define ZXNOTHROW ZXATTR( __nothrow__    )

#if ZX_MSC >= 800
#define ZXLL( VAL ) VAL##I64
#define ZXILL __int64
#define ZXB1  1I64
#define ZXB1U 1I64
#elif ZXCPP || ZXSTDC >= 199900L || ZX_GCC || ZX_GPP
#define ZXILL long long
#define ZXLL( VAL ) VAL##LL
#define ZXB1  1LL
#define ZXB1U 1ULL
#else
#define ZXLL( VAL ) VAL
#define ZXB1  1
#define ZXB1U 1U
#endif

#ifdef ZXILL
typedef          ZXILL zxill;
typedef unsigned ZXILL zxull;
typedef   signed ZXILL zxsll;
#endif

#endif
