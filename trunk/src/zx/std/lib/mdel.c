#include <zx/std/lib.h>
ZXCORE void* mdel( void* ptr )
{
  if ( ptr )
    free( ptr );
  return NULL;
}
