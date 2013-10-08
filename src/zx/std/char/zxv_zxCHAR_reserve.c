#include <zx/std/char.h>
ZXCORE_EXP void zxv_zxCHAR_reserve( zxCHAR *txt, size_t minSize )
{
  if ( !txt )
    return;
  minSize += sizeof( char );
  zxv.reserve( &txt->m_data, minSize );
  --txt->m_data.m_count;
  txt->m_data.m_size -= sizeof( char );
  txt->m_text = (char*)txt->m_data.m_data;
}