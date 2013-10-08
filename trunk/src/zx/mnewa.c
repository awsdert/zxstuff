#include <zx/std/lib.h>
ZXCORE_EXP ZXVP mnewa( size_t Tsize, size_t count, ZXVP cpy )
{
  size_t size = Tsize * count, i = 0;
  zxuc   *ptr = (zxuc*)malloc( size );
  if ( ptr )
  {
    if ( cpy )
    {
      for ( ; i < size; i += Tsize )
        memcpy( &ptr[ i ], cpy, Tsize );
    }
    else
      memset( ptr, 0, size );
  }
  return ptr;
}
