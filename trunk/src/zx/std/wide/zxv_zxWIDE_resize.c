#include <zx/std/wide.h>
ZXCORE_EXP void zxv_zxWIDE_resize( zxWIDE *txt, size_t setLen, wide setNew )
{
  if ( !txt )
    return;
  zxv.resize( &txt->m_data, setLen + 1, (zxuc*)&setNew );
  --txt->m_data.m_count;
  txt->m_data.m_size -= sizeof( wide );
  txt->m_text = (wide*)txt->m_data.m_data;
  txt->m_text[ 0 ] = 0;
}