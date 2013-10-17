#include <zx/std/lib.h>
ZXCORE_EXP void* mdel( void* ptr )
{
  if ( ptr )
    free( ptr );
  return NULL;
}
