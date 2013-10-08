#include <zx/std/char.h>
ZXCORE_EXP size_t zxv_zxCHAR_copy( zxCHAR const *txt, char *dst, size_t const len, size_t const from )
{
  if ( !txt )
    return 0;
  return zxv.copy( &txt->m_data, (zxuc*)dst, len, from );
}