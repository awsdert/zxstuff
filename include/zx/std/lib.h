#include "../limits.h"
#if ZXCPP
#include <cstdlib>
#else
#include <stdlib.h>
#endif
#ifndef ZXSTDLIB
#define ZXSTDLIB
ZXC_OPEN
ZXCORE ZXVP mnew( size_t size, ZXVP cpy );
ZXCORE ZXVP mnewa( size_t Tsize, size_t count, ZXVP cpy );
ZXCORE ZXVP mrenew( ZXVP dst, size_t count, size_t Tsize, size_t newCount,
                    ZXVP cpy );
ZXCORE ZXVP mdel( ZXVP ptr );
ZXC_SHUT
#endif
