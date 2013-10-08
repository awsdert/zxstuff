#include <zx/std/char.h>
ZXCORE_EXP size_t zxv_zxCHAR_len( const char* src )
{
  size_t len = 0;
  if ( src )
  {
    while ( src[ len ] != 0u && len < SCHAR_MAX )
      ++len;
  }
  return len;
}
