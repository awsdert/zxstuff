#include <zx/std/vector.h>
ZXCORE_EXP zxuc* zxv_zxVECTOR_at( zxVECTOR const *obj, size_t const i )
{
  zxuc *c = (zxuc*)0;
  if ( !obj )
  {
    assert( !obj );
    return c;
  }
  if ( !obj->m_data )
  {
    assert( !obj->m_data );
    return c;
  }
  if ( i >= obj->m_count )
  {
    assert( i >= obj->m_count );
    return c;
  }
  return &obj->m_data[ i * obj->m_Tsize ];
}
