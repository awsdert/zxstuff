#include <zx/std/wide.h>
ZXCORE_EXP void zxv_zxWIDE_shrink( zxWIDE *obj, size_t const setCount )
{
  --obj->m_data.m_count;
  zxv.shrink( &obj->m_data, setCount );
  obj->m_text = (wide*)obj->m_data.m_data;
  obj->m_text[ obj->m_data.m_count - 1 ] = 0u;
}