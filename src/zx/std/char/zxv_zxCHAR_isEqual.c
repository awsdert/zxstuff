#include <zx/std/char.h>
ZXCORE_EXP bool zxv_zxCHAR_isEqual( zxCHAR const *txt, zxCHAR const *src, size_t *i )
{
  if ( i )
    *i = SIZE_MAX;
  if ( !txt || !src )
    return ( txt == src );
  return zxv.isEqual( &txt->m_data, &src->m_data, i );
}