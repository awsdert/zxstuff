#include <zx/std/char.h>
ZXCORE_EXP void zxv_zxCHAR_append( zxCHAR *txt, zxCHAR const *src, size_t pos )
{
  if ( !txt )
    return;
  zxv.append( &txt->m_data, &src->m_data, pos );
  zxv.grow( &txt->m_data, txt->m_data.m_count + 1, NULL );
  --txt->m_data.m_count;
  txt->m_data.m_size -= sizeof( char );
}
