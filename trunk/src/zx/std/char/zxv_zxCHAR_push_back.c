#include <zx/std/char.h>
ZXCORE_EXP bool zxv_zxCHAR_push_back( zxCHAR *txt, zxCHAR const *src )
{
  if ( !txt || !src )
    return false;
  if ( !zxv.push_back( &txt->m_data, &src->m_data ) )
    return false;
  if ( txt->m_data.m_count == txt->m_data.m_fullCount )
  {
    zxv.grow( &txt->m_data, txt->m_data.m_count + 1, NULL );
    --txt->m_data.m_count;
    txt->m_data.m_size -= sizeof( char );
  }
  txt->m_text = (char*)txt->m_data.m_data;
  return true;
}