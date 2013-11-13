#pragma once
#ifndef ZXCORE
#include "sys.h"

#ifdef ZXUSE_DLL
#define ZXUSE_CORE
#define ZXUSE_SYS
#elif defined( ZXBUILD_DLL )
#define ZXBUILD_CORE
#define ZXBUILD_SYS
#endif

#ifdef ZXUSE_CORE
#define ZXCORE      ZXDLL_IMP
#define ZXCORE_CALL
#elif defined( ZXBUILD_CORE )
#define ZXCORE      ZXDLL_EXP
#define ZXCORE_CALL
#else
#define ZXCORE
#define ZXCORE_CALL
#endif

#ifdef ZXUSE_SYS
#define ZXSYS     ZXDLL_IMP
#define ZXSYS_CALL
#elif defined( ZXBUILD_SYS )
#define ZXSYS     ZXDLL_EXP
#define ZXSYS_CALL
#else
#define ZXSYS
#define ZXSYS_CALL
#endif

#endif
