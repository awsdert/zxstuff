#include <zx/std/lib.h>
ZXCORE_EXP void mcpy( ZXVP dst, ZXVP const src, size_t const size )
{
  size_t i = 0;
  zxuc *d = (zxuc*)dst, *s = (zxuc*)src;
  for ( ; i < size; ++i )
    d[ i ] = s[ i ];
}