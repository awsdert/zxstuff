#include <zx/std/wide.h>
ZXCORE_EXP size_t zxWIDE_len( const wide* src )
{
  return wcslen( src );
}

