#include <zx/std/vector.h>
ZXCORE_EXP bool zxv_zxVECTOR_empty( zxVECTOR const *obj )
{
  return ( !obj || !obj->m_data || !obj->m_size || !obj->m_count );
}