#include <zx/std/lib.h>
ZXCORE void* mrenew(
  void   *dst,
  size_t count,
  size_t const Tsize,
  void   const *cpy,
  size_t setCount )
{
  size_t size = Tsize * setCount, i = 0;
  zxuc   *ptr = (zxuc*)realloc( dst, size );
  if ( ptr && count < setCount )
  {
    i = Tsize * count;
    if ( cpy )
    {
      for ( ; i < size; i += Tsize )
        mcpy( &ptr[ i ], cpy, Tsize );
    }
    else
      mset( &ptr[ i ], 0, size - i );
  }
  return ptr;
}
