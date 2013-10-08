#include <zx/std/char.h>
ZXCORE_EXP void zxv_zxCHAR_reverse( zxCHAR *txt )
{
  if ( !txt )
    return;
  zxv.reverse( &txt->m_data );
}
