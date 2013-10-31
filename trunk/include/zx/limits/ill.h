#pragma once
#include "all.h"
#ifndef ZXILL_H

#ifdef LLONG_MAX
#define ZXUILL_MAX ULLONG_MAX
#define ZXILL_MAX  LLONG_MAX
#define ZXILL_MIN  LLONG_MIN
#elif defined( LONG_LONG_MAX )
#define ZXUILL_MAX ULONG_LONG_MAX
#define ZXILL_MAX  LONG_LONG_MAX
#define ZXILL_MIN  LONG_LONG_MIN
#elif UINT_MAX > 0xFFFFFFFFU
#ifndef ZXILL
#define ZXILL int
#endif
#define ZXUILL_MAX UINT_MAX
#define ZXILL_MAX  INT_MAX
#define ZXILL_MIN  INT_MIN
#endif

#ifdef ZXUILL_MAX
#define ZXILL_BITS ZX_MB( ZXUILL_MAX )
#else
#define ZXILL_BITS 0
#endif

#endif
