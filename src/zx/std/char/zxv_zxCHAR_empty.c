#include <zx/std/char.h>
ZXCORE_EXP bool zxv_zxCHAR_empty( zxCHAR const *txt )
{
  if ( !txt )
    return true;
  return zxv.empty( &txt->m_data );
}