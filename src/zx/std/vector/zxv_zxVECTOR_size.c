#include <zx/std/vector.h>
ZXCORE_EXP size_t zxv_zxVECTOR_size( zxVECTOR const *obj )
{
  if ( !obj )
    return 0;
  return obj->m_count;
}
ZXCORE_EXP size_t zxc_zxVECTOR_max_size( zxVECTOR const *obj )
{
  if ( !obj )
    return 0;
  return obj->m_fullCount;
}
ZXCORE_EXP size_t zxc_zxVECTOR_capacity( zxVECTOR const *obj )
{
  if ( !obj )
    return 0;
  return obj->m_fullSize;
}
ZXCORE_EXP bool   zxc_zxVECTOR_empty( zxVECTOR const *obj )
{
  return ( obj && obj->m_data && obj->m_size );
}