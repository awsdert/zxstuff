#include <zx/std/lib.h>
ZXCORE void mcpy( void* dst, void const *cpy, size_t const size )
{
  size_t i = 0;
  zxuc *d = (zxuc*)dst, *c = (zxuc*)cpy;
  for ( ; i < size; ++i )
    d[ i ] = c[ i ];
}
