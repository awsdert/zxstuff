#include <zx/std/char.h>
ZXCORE_EXP size_t zxv_zxCHAR_max_size( zxCHAR const *txt )
{
  if ( !txt )
    return 0;
  return zxv.max_size( &txt->m_data );
}