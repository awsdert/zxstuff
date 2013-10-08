#include <zx/std/char.h>
ZXCORE_EXP size_t zxv_zxCHAR_capacity( zxCHAR const *txt )
{
  if ( !txt )
    return 0;
  return zxv.capacity( &txt->m_data );
}