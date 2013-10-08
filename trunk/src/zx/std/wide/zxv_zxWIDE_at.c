#include <zx/std/wide.h>
ZXCORE_EXP wide* zxv_zxWIDE_at( zxWIDE const *txt, size_t const i )
{
  if ( !txt )
    return (wide*)0;
  return (wide*)zxv.at( &txt->m_data, i );
}