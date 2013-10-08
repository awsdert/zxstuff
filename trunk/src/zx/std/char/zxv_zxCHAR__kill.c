#include <zx/std/char.h>
ZXCORE_EXP void zxv_zxCHAR__kill( zxCHAR *txt )
{
  if ( !txt )
    return;
  zxv._kill( &txt->m_data );
  txt->m_text = NULL;
}
