#include <zx/std/char.h>
ZXCORE_EXP void zxv_zxCHAR_shrink_to_fit( zxCHAR *txt )
{
  if ( !txt )
    return;
  zxv.shrink_to_fit( &txt->m_data );
}