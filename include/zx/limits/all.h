#include "../dll.h"

#if ZXCPP
#include <cstddef>
#include <climits>
#else
#include <stddef.h>
#include <limits.h>
#endif

#ifndef ZXLIMITS_ALL_H
#define ZXLIMITS_ALL_H

ZXC_OPEN

#define ZX__MB(  V, B )(((V) & ( ZXB1U << (B))) != 0)
#define ZX_MB1(  V, B )  ZX__MB(  V, B ) + ZX__MB(  V, B + 1 )
#define ZX_MB2(  V, B )  ZX_MB1(  V, B ) + ZX_MB1(  V, B + 2 )
#define ZX_MB4(  V, B )  ZX_MB2(  V, B ) + ZX_MB2(  V, B + 4 )
#define ZX_MB8(  V, B )  ZX_MB4(  V, B ) + ZX_MB4(  V, B + 8 )
#define ZX_MB16( V, B )  ZX_MB8(  V, B ) + ZX_MB8(  V, B + 16 )
#define ZX_MB(   V )   ( ZX_MB16( V, 0 ) + ZX_MB16( V, 32 ) )
#define ZX_LB( V ) (ZXB1U << ( V - 1 ))

ZXC_SHUT
#endif