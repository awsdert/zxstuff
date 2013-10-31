#pragma once
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

#define ZX__MB( UV, M ) (((UV)&(ZXB1U<<(CHAR_BIT*(M))))!=0U)
#define ZX_MB1( UV, M ) ZX__MB( UV, M ) + ZX__MB( UV, M + 1 )
#define ZX_MB2( UV, M ) ZX_MB1( UV, M ) + ZX_MB1( UV, M + 2 )
#define ZX_MB( UV ) ( ZX_MB2( UV, 0 ) + ZX_MB2( UV, 4 ) ) * CHAR_BIT
#define ZX_LB( V ) (ZXB1U << ((V) - 1))

#endif