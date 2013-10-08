#include <zx/std/wide.h>
ZXCORE_EXP bool zxv_zxWIDE_isEqual( zxWIDE const *txt, zxWIDE const *src, size_t *i )
{
  if ( i )
    *i = SIZE_MAX;
  if ( !txt || !src )
    return ( txt == src );
  return zxv.isEqual( &txt->m_data, &src->m_data, i );
}