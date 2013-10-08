#include <zx/std/vector.h>
ZXCORE_EXP void zxv_zxVECTOR_reverse( zxVECTOR *obj )
{
  size_t i, d, s;
  zxuchr *tmp;
  if ( !obj )
  {
    assert( !obj );
    return;
  }
  tmp = (zxuchr*)malloc( obj->m_size );
  memcpy( tmp, obj->m_data, obj->m_size );
  s = obj->m_size - obj->m_Tsize;
  for ( i = 0, d = 0; i < obj->m_count; ++i, d += obj->m_Tsize, s -= obj->m_Tsize )
    memcpy( &obj->m_data[ d ], &tmp[ s ], obj->m_Tsize );
  free( tmp );
}