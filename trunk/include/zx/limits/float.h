#include "all.h"
#ifndef ZXFLT_BITS

#if ( FLT_MANT_DIG == 24 )
#define ZXFLT_BITS 32
#else
#define ZXFLT_BITS 0
#endif

#if ( DBL_MANT_DIG == 53 )
#define ZXDBL_BITS 64
#else
#define ZXDBL_BITS 0
#endif

#if ( LDBL_MANT_DIG == 53 )
#define ZXLDBL_BITS 64
#elif ( LDBL_MANT_DIG == 119 )
#define ZXLDBL_BITS 128
#else
#define ZXLDBL_BITS ZXDBL_BITS
#endif

#endif