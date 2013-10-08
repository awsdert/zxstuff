#include <zx/std/char.h>
ZXCORE_EXP char& zxv_zxCHAR_at( zxCHAR const *txt, size_t i )
{
  if ( !txt )
    return *(char*)0;
  return *(char*)zxv.at( &txt->m_data, i );
}