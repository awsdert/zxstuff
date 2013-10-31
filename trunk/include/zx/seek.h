#pragma once
#include "std/int.h"
#ifndef __cplusplus

#include <stdio.h>

#else

#include <cstdio>

#endif

#ifndef zxSeek_h
#define zxSeek_h

typedef enum zxSeek_enum
{
	zxSEEK_HOME = SEEK_SET,
	zxSEEK_NOW	= SEEK_CUR,
	zxSEEK_END	= SEEK_END,
	zxSEEK_COUNT
} zxSeek;

/*
#define zxSEEK_HOME	SEEK_SET
#define zxSEEK_NOW	SEEK_CUR
#define zxSEEK_END	SEEK_END
#define zxSEEK_COUNT 3
#define zxSEEK_T	si08
#define zxSEEK_TYPE	zxSEEK_T
*/

/*
	Using UNIX style access here
	0x0#00 = owner
	0x00#0 = group users
	0x000# = other users
	8 = Append, needed to avoid accidently destroying file contents ( not part of unix standard )
*/
#define ZXACCESS_CREATE	0x10000
#define ZXACCESS_APPEND	0x20000
#define ZXACCESS_X      0x100
#define ZXACCESS_W      0x200
#define ZXACCESS_R      0x400
#define ZXACCESS_ALL    0x700
#define ZXACCESS_GX     0x010
#define ZXACCESS_GW     0x020
#define ZXACCESS_GR     0x040
#define ZXACCESS_GALL   0x070
#define ZXACCESS_OX     0x1
#define ZXACCESS_OW     0x2
#define ZXACCESS_OR     0x4
#define ZXACCESS_OALL   0x7
#define ZXACCESS_FX     0x111
#define ZXACCESS_FW     0x222
#define ZXACCESS_FR     0x444
#define ZXACCESS_FALL   0x777

#endif
