#include "all.h"

#pragma once
#ifndef ZXSIZE_BITS

#if ZXMSW == 64
#define ZXSIZE_TYPE __int64
#define ZXSIZE_SYS
#define ZXSIZE_MAX  _UI64_MAX
#define ZXSSIZE_MAX _I64_MAX
#define ZXSSIZE_MIN _I64_MIN
#elif ZXMSW == 32
#define ZXSIZE_TYPE int
#ifndef _W64
#define _W64
#endif
#define ZXSIZE_SYS  _W64
#define ZXSIZE_MAX  UINT_MAX
#define ZXSSIZE_MAX INT_MAX
#define ZXSSIZE_MIN INT_MIN
#else
#define ZXSIZE_TYPE int
#define ZXSIZE_SYS
#define ZXSIZE_MAX  UINT_MAX
#define ZXSSIZE_MAX INT_MAX
#define ZXSSIZE_MIN INT_MIN
#endif

#define ZXSIZE_BITS ZX_MB( ZXSIZE_MAX )

#ifndef __SIZE_TYPE__
#define __SIZE_TYPE__
#endif

#ifndef _SIZE_T_DEFINED
#define _SIZE_T_DEFINED
#endif

#ifndef SIZE_MAX
typedef ZXSIZE_SYS unsigned ZXSIZE_TYPE size_t;
#define SIZE_MAX ZXSIZE_MAX
#endif

#if !defined( SSIZE_MAX )
typedef ZXSIZE_SYS signed   ZXSIZE_TYPE ssize_t;
#define SSIZE_MAX ZXSSIZE_MAX
#define SSIZE_MIN ZXSSIZE_MIN
#endif

#endif
