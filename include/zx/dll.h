#include "sys.h"

#pragma once
#ifndef ZXCORE

#ifdef ZXUSE_DLL
#define ZXUSE_CORE
#define ZXUSE_SYS
#elif defined( ZXBUILD_DLL )
#define ZXBUILD_CORE
#define ZXBUILD_SYS
#endif

#ifdef ZXUSE_CORE
#define ZXCORE      ZXDLL_IMP
#define ZXCORE_EXP  ZXDLL_EXP
#define ZXCORE_CALL __cdecl
#elif defined( ZXBUILD_CORE )
#define ZXCORE      ZXDLL_EXP
#define ZXCORE_EXP
#define ZXCORE_CALL __cdecl
#else
#define ZXCORE
#define ZXCORE_EXP
#define ZXCORE_CALL
#endif

#ifdef ZXUSE_SYS
#define ZXSYS     ZXDLL_IMP
#define ZXSYS_EXP ZXDLL_EXP
#define ZXSYS_CALL __cdecl
#elif defined( ZXBUILD_SYS )
#define ZXSYS     ZXDLL_EXP
#define ZXSYS_EXP
#define ZXSYS_CALL __cdecl
#else
#define ZXSYS
#define ZXSYS_EXP
#define ZXSYS_CALL
#endif

#endif
