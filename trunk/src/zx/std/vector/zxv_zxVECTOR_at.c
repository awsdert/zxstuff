#include <zx/std/vector.h>
ZXCORE_EXP zxuc* zxv_zxVECTOR_at( zxVECTOR const *obj, size_t const i )
{
  ZXASSERT( !obj || !obj->m_data || i >= obj->m_count )
    return NULL;
  return &((zxuc*)obj->m_data)[ i * obj->m_Tsize ];
}
