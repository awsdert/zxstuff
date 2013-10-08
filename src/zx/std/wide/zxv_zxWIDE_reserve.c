#include <zx/std/wide.h>
ZXCORE_EXP void zxv_zxWIDE_reserve( zxWIDE *txt, size_t minSize )
{
  if ( !txt )
    return;
  minSize += sizeof( char );
  zxv.reserve( &txt->m_data, minSize );
  --txt->m_data.m_count;
  txt->m_data.m_size -= sizeof( wide );
  txt->m_text = (wide*)txt->m_data.m_data;
}