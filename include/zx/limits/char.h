#include "all.h"
#ifndef ZXCHAR_BITS

#define ZXCHAR_BITS CHAR_BIT
#define ZXUCHAR_MAX UCHAR_MAX
#define ZXSCHAR_MAX SCHAR_MAX
#define ZXSCHAR_MIN SCHAR_MIN
#define ZXCHAR_MAX  CHAR_MAX
#define ZXCHAR_MIN  CHAR_MIN

static zxuc ZXUNUSED( zxLastCharBit ) = ZX_LB( CHAR_BIT );

#endif
