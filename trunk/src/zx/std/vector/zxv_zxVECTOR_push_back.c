#include <zx/std/vector.h>
ZXCORE_EXP bool zxv_zxVECTOR_push_back( zxVECTOR *obj, zxVECTOR const *src )
{
  size_t i, j = 0, stop;
  if ( !obj )
  {
    assert( !obj );
    return false;
  }
  if ( !src )
  {
    assert( !src );
    return false;
  }
  i = obj->m_count;
  stop = i + src->m_count;
  zxv.grow( obj, obj->m_count + src->m_count, NULL );
  for ( ; i < stop; ++i, ++j )
    obj->m_data[ i ] = src->m_data[ j ];
  return true;
}