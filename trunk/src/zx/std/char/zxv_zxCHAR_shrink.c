#include <zx/std/char.h>
ZXCORE_EXP void zxv_zxCHAR_shrink( zxCHAR *txt, size_t setLen )
{
  if ( !txt )
    return;
  zxv.shrink( &txt->m_data, setLen + 1 );
  --txt->m_data.m_count;
  txt->m_data.m_size -= sizeof( char );
}
