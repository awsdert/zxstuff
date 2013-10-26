#pragma once
#include "sys.h"
#ifndef ZXCORE

#ifdef ZXUSE_DLL
#define ZXUSE_CORE
#define ZXUSE_SYS
#elif ZXBUILD_DLL
#define ZXBUILD_CORE
#define ZXBUILD_SYS
#endif

#ifdef ZXUSE_CORE
#define ZXCORE     ZXDLL_IMP
#define ZXCORE_EXP ZXDLL_EXP
#elif defined( ZXBUILD_CORE )
#define ZXCORE     ZXDLL_EXP
#define ZXCORE_EXP ZXDLL_EXP
#else
#define ZXCORE
#define ZXCORE_EXP
#endif

#ifdef ZXUSE_SYS
#define ZXSYS     ZXDLL_IMP
#define ZXSYS_EXP ZXDLL_EXP
#elif defined( ZXBUILD_SYS )
#define ZXSYS     ZXDLL_EXP
#define ZXSYS_EXP ZXDLL_EXP
#else
#define ZXSYS
#define ZXSYS_EXP
#endif

#endif
