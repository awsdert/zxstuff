#include <zx/std/wide.h>
ZXCORE_EXP size_t zxv_zxWIDE_len( const wide* src )
{
  size_t len = 0;
  if ( src )
  {
    while ( src[ len ] != 0u && len < SCHAR_MAX )
      ++len;
  }
  return ++len;
}

