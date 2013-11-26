#pragma once
#ifndef ZX_LIMITS_BOOL_H
#define ZX_LIMITS_BOOL_H
#include "all.h"

#ifndef __bool_true_false_are_defined
#if !ZXCPP && !defined( _BOOL )
#define _BOOL
ZXC_OPEN
typedef zxuc bool;
static const bool true  = 1u;
static const bool false = 0u;
ZXC_SHUT
#endif
#define __bool_true_false_are_defined
#endif

#if !ZXCPP
#define ZXPRINTFBOOL int
#else
#define ZXPRINTFBOOL bool
#endif

#endif
