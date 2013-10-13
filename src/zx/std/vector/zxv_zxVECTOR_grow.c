#include <zx/std/vector.h>
ZXCORE_EXP void zxv_zxVECTOR_grow( zxVECTOR *obj, size_t setCount, zxuc const *setNew )
{
  size_t d, t, j, size;
  zxuc *des;
  ZXASSERT( !obj )
    return;
  if ( obj->m_isFixed || setCount <= obj->m_count )
    return;
  size = setCount++ * obj->m_Tsize;
  obj->m_data = realloc( obj->m_data, size );
  des = (zxuc*)obj->m_data;
  d = obj->m_count;
  t = obj->m_size;
  if ( setNew )
  {
    for ( ; d < setCount; ++d )
    {
      for ( j = 0; j < obj->m_Tsize; ++j )
        des[ t ] = setNew[ j ];
    }
  }
  else
  {
    for ( ; d < setCount; ++d )
    {
      for ( j = 0; j < obj->m_Tsize; ++j )
        des[ t ] = 0u;
    }
  }
  if ( obj->m_ptr )
    *obj->m_ptr = obj->m_data;
}
