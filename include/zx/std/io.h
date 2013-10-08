#include "../sys.h"
#ifdef __STRICT_ANSI__
#undef __STRICT_ANSI__
#if ZXCPP
#include <cstdio>
#else
#include <stdio.h>
#endif
#include <io.h>
#define __STRICT_ANSI__
#else
#if ZXCPP
#include <cstdio>
#else
#include <stdio.h>
#endif
#include <io.h>
#endif
