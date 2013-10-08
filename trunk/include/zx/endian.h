#include "std/int.h"

#ifndef ZXENDIAN_H
#define ZXENDIAN_H

ZXC_OPEN

typedef enum zxENDIAN
{
	zxENDIAN_LITTLE = 0,
	zxENDIAN_BIG,
	zxENDIAN_PDP,
	zxENDIAN_COUNT
} zxEndian;

ZXCORE zxEndian zxIntEndian( void );
/* Will return malloc() buffer if des is NULL */
ZXCORE zxuchr* zxcopy(
  zxuchr* src, size_t ssize, zxEndian sen,
	zxuchr* des, size_t dsize, zxEndian den );
ZXCORE zxuchr* zxcopybits(
  zxuchr* src, size_t sbits, zxEndian sen,
	zxuchr* des, size_t dbits, zxEndian den,
  size_t from, size_t to );

ZXC_SHUT

#endif