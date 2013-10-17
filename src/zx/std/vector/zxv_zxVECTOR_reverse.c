#include <zx/std/vector.h>
ZXCORE_EXP void zxv_zxVECTOR_reverse( zxVECTOR *obj )
{
  size_t i, d, s;
  zxuc *tmp, *VEC;
  ZXASSERT( !obj )
    return;
  VEC = (zxuc*)obj->m_data;
  tmp = (zxuc*)malloc( obj->m_size );
  mcpy( tmp, obj->m_data, obj->m_size );
  s = obj->m_size - obj->m_Tsize;
  for ( i = 0, d = 0; i < obj->m_count;
    ++i, d += obj->m_Tsize, s -= obj->m_Tsize )
    mcpy( &VEC[ d ], &tmp[ s ], obj->m_Tsize );
  free( tmp );
}