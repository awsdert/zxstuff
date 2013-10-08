#include <zx/std/char.h>
ZXCORE_EXP void zxv_zxCHAR_clear( zxCHAR *txt )
{
  if ( !txt )
    return;
  zxv.clear( &txt->m_data );
  txt->m_text = NULL;
}