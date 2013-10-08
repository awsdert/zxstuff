#include <zx/std/wide.h>
ZXCORE_EXP void zxv_zxWIDE_reverse( zxWIDE *obj )
{
  size_t tmp;
  if ( !obj )
    return;
  tmp = obj->m_data.m_count;
  --obj->m_data.m_count;
  zxv.reverse( &obj->m_data );
  obj->m_data.m_count = tmp;
}
