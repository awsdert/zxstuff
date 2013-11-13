#pragma once
#ifndef ZXENDIAN_H
#define ZXENDIAN_H
#include "std/int.h"
#include "std/lib.h"

ZXC_OPEN

typedef enum zxENDIAN
{
  zxENDIAN_LITTLE = 0,
  zxENDIAN_BIG,
  zxENDIAN_PDP,
  zxENDIAN_COUNT
} zxEndian;

ZXCORE zxEndian zxIntEndian( void );
/* Will return malloc() buffer if dst is NULL */
ZXCORE zxuc* zxcopy(
  zxuc* src, size_t ssize, zxEndian sen,
  zxuc* dst, size_t dsize, zxEndian den );
ZXCORE zxuc* zxcopybits(
  zxuc* src, size_t sbits, zxEndian sen,
  zxuc* dst, size_t dbits, zxEndian den,
  size_t from, size_t to );

ZXC_SHUT

#endif