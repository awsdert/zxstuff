#include <zx/std/lib.h>
ZXCORE_EXP void mset( void* ptr, zxuc const value, size_t const size )
{
  size_t i = 0;
  zxuc *dst = (zxuc*)ptr;
  for ( ; i < size; ++i )
    dst[ i ] = value;
}