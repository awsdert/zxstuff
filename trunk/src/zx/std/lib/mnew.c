#include <zx/std/lib.h>
ZXCORE_EXP void* mnew( size_t const Tsize, void const *cpy )
{
  void* ptr = malloc( Tsize );
  if ( ptr )
  {
    if ( cpy )
      mcpy( ptr, cpy, Tsize );
    else
      mset( ptr, 0, Tsize );
  }
  return ptr;
}
