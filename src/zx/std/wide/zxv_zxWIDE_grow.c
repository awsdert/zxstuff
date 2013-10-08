#include <zx/std/wide.h>
ZXCORE_EXP void zxv_zxWIDE_grow( zxWIDE *obj, size_t const setCount, wide const setNew )
{
  if ( !obj )
    return;
  --obj->m_data.m_count;
  zxv.grow( &obj->m_data, setCount, (zxuc*)&setNew );
  obj->m_text = (wide*)obj->m_data.m_data;
  obj->m_text[ obj->m_data.m_count - 1 ] = 0u;
}

