#include <zx/std/lib.h>
ZXCORE_EXP ZXVP mrenew( ZXVP dst, size_t count, size_t Tsize, size_t newCount, ZXVP cpy )
{
  size_t size = Tsize * newCount, i = 0;
  zxuc   *ptr = (zxuc*)realloc( dst, size );
  if ( ptr && count < newCount )
  {
    i = Tsize * count;
    if ( cpy )
    {
      for ( ; i < size; i += Tsize )
        memcpy( &ptr[ i ], cpy, Tsize );
    }
    else
      memset( &ptr[ i ], 0, size - i );
  }
  return ptr;
}
