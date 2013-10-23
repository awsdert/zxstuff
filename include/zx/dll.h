#pragma once
#include "sys.h"
#ifndef ZXCORE

#ifdef ZXCORE_DLL
#define ZXCORE     ZXDLL_IMP
#define ZXCORE_EXP ZXDLL_EXP
#elif  ZXCORE_DLL_BUILD
#define ZXCORE     ZXDLL_EXP
#define ZXCORE_EXP ZXDLL_EXP
#else
#define ZXCORE
#define ZXCORE_EXP
#endif

#ifdef ZXSYS_DLL
#define ZXSYS     ZXDLL_IMP
#define ZXSYS_EXP ZXDLL_EXP
#elif  ZXSYS_DLL_BUILD
#define ZXSYS     ZXDLL_EXP
#define ZXSYS_EXP ZXDLL_EXP
#else
#define ZXSYS
#define ZXSYS_EXP
#endif

#endif
