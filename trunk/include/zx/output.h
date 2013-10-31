#pragma once
#include "zxCore.h"
#ifndef zxOutput_h
#define zxOutput_h

enum zxGFX_TYPE
{
	zxGFX_OGL = 0,
#if ZXMSW
	zxGFX_DX,
#endif
	zxGFX_SYS,
	zxGFX_COUNT,
};

enum zxSFX_TYPE
{
	zxSFX_OAL = 0,
#ifdef ZXMSW
	zxSFX_DX,
#endif
	zxSFX_SYS,
	zxSFX_COUNT
};

#endif
