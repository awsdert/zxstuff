#include <zx/std/char.h>
ZXCORE_EXP void zxv_zxCHAR_pop_back( zxCHAR *txt )
{
  if ( !txt )
    return;
  zxv.pop_back( &txt->m_data );
}