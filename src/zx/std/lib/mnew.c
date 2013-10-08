#include <zx/std/lib.h>
ZXCORE_EXP ZXVP mnew( size_t size, ZXVP cpy )
{
  ZXVP ptr = malloc( size );
  if ( ptr )
  {
    if ( cpy )
      mcpy( ptr, cpy, size );
    else
      mset( ptr, 0, size );
  }
  return ptr;
}
