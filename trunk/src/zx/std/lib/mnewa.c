#include <zx/std/lib.h>
ZXCORE void* mnewa(
  size_t const Tsize,
  void   const *cpy,
  size_t count )
{
  size_t size = Tsize * count, i = 0;
  zxuc   *ptr = (zxuc*)malloc( size );
  if ( ptr )
  {
    if ( cpy )
    {
      do
      {
        mcpy( &ptr[ i ], cpy, Tsize );
        i += Tsize;
      }
      while ( i < size );
    }
    else
      mset( ptr, 0, size );
  }
  return ptr;
}
