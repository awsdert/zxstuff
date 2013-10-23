#pragma once
#include "vector.h"
#include "math.h"
#include <wchar.h>

#if ZXCPP
#include <string>
#else
#include <string.h>
#endif

#ifndef ZX_TEXT_H
#define ZX_TEXT_H

#ifndef WIDE_DEFINED
#define WIDE_DEFINED
typedef wchar_t wide;
#endif

#ifdef _MSC_VER
	#define ZXPRINTF_USIZE_T	ZXT("%Iu")
	#define ZXPRINTF_SSIZE_T	ZXT("%Id")
	#define ZXPRINTF_XSIZE_T	ZXT("%IX")
	#define ZXPRINTF_PTRDIFF_T	ZXT("%Id")
#elif defined( __GNUC__ )
	#define ZXPRINTF_USIZE_T	ZXT("%zu")
	#define ZXPRINTF_SSIZE_T	ZXT("%zd")
	#define ZXPRINTF_XSIZE_T	ZXT("%zX")
	#define ZXPRINTF_PTRDIFF_T	ZXT("%zd")
#else
	#define ZXPRINTF_USIZE_T	ZXT("%u")
	#define ZXPRINTF_SSIZE_T	ZXT("%d")
	#define ZXPRINTF_XSIZE_T	ZXT("%X")
	#define ZXPRINTF_PTRDIFF_T	ZXT("%d")
#endif

#endif