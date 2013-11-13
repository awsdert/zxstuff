#include <zx/std/wide.h>
ZXCORE size_t zxWIDE_len( const wide* src )
{
  return wcslen( src );
}

