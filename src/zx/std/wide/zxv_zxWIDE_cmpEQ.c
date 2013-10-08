#include <zx/std/wide.h>
ZXCORE_EXP bool zxv_zxWIDE_cmpEQ( zxWIDE const *txt, zxWIDE const *src )
{
  if ( !txt || !src )
    return ( txt == src );
  return zxv.isEqual( &txt->m_data, &src->m_data, NULL );
}