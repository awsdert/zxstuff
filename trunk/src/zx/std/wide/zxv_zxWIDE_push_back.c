#include <zx/std/wide.h>
ZXCORE_EXP bool zxv_zxWIDE_push_back( zxWIDE *txt, zxWIDE const *src )
{
  if ( !txt || !src )
    return false;
  if ( !zxv.push_back( &txt->m_data, &src->m_data ) )
    return false;
  if ( txt->m_data.m_count == txt->m_data.m_fullCount )
  {
    zxv.grow( &txt->m_data, txt->m_data.m_count + 1, NULL );
    --txt->m_data.m_count;
    txt->m_data.m_size -= sizeof( wide );
  }
  txt->m_text = (wide*)txt->m_data.m_data;
  return true;
}