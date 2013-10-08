#include <zx/std/char.h>
ZXCORE_EXP void zxv_zxCHAR_resize( zxCHAR *txt, size_t setLen, char setNew )
{
  if ( !txt )
    return;
  zxv.resize( &txt->m_data, setLen + 1, (zxuc*)&setNew );
  --txt->m_data.m_count;
  txt->m_data.m_size -= sizeof( char );
  txt->m_text = (char*)txt->m_data.m_data;
  txt->m_text[ 0 ] = 0;
}