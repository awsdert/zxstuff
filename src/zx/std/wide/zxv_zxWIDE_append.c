#include <zx/std/wide.h>
ZXCORE_EXP void zxv_zxWIDE_append( zxWIDE *obj, zxWIDE const *src, size_t pos )
{
  if ( !obj || !src || !src->m_data.m_data )
    return;
  --obj->m_data.m_count;
  zxv.append( &obj->m_data, &src->m_data, pos );
  obj->m_text = (wide*)obj->m_data.m_data;
  obj->m_text[ obj->m_data.m_count - 1 ] = 0u;
}