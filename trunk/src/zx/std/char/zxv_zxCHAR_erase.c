#include <zx/std/char.h>
ZXCORE_EXP void zxv_zxCHAR_erase( zxCHAR *txt, size_t first, size_t last )
{
  if ( !txt )
    return;
  zxv.erase( &txt->m_data, first, last );
}
