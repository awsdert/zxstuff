#include <zx/std/wide.h>
ZXCORE_EXP void zxv_zxWIDE_erase( zxWIDE *obj, size_t first, size_t last )
{
  --obj->m_data.m_count;
  zxv.erase( &obj->m_data, first, last );
  obj->m_text[ obj->m_data.m_count - 1 ] = 0u;
}
