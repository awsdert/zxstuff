#pragma once
#include "ill.h"
#include "int.h"
#ifndef ZXIMAX

#ifdef ZXUILL_MAX
#define ZXIMAX      ZXILL
#define ZXIMAX_BITS ZXILL_BITS
#define ZXUIMAX_MAX ZXUILL_MAX
#define ZXIMAX_MAX  ZXILL_MAX
#define ZXIMAX_MIN  ZXILL_MIN
#else
#define ZXIMAX      int
#define ZXIMAX_BITS ZXINT_BITS
#define ZXUIMAX_MAX ZXUINT_MAX
#define ZXIMAX_MAX  ZXINT_MAX
#define ZXIMAX_MIN  ZXINT_MIN
#endif

typedef          ZXIMAX zxim;
typedef   signed ZXIMAX zxsm;
typedef unsigned ZXIMAX zxum;

#endif
