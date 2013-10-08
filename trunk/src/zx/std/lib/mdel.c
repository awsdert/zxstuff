#include <zx/std/lib.h>
ZXCORE_EXP ZXVP mdel( ZXVP ptr )
{
  if ( ptr )
    free( ptr );
  return NULL;
}
