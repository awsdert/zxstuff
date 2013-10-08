#include <zx/std/vector.h>
ZXCORE_EXP void zxv_zxVECTOR_grow( zxVECTOR *obj, size_t setCount, zxuc const *setNew )
{
  size_t d, t, j, size;
  if ( !obj )
  {
    assert( !obj );
    return;
  }
  if ( setCount <= obj->m_count )
    return;
  size = setCount++ * obj->m_Tsize;
  if ( !obj->m_data )
    obj->m_data = (zxuchr*)malloc( size );
  else
    obj->m_data = (zxuchr*)realloc( obj->m_data, size );
  d = obj->m_count;
  t = obj->m_size;
  if ( setNew )
  {
    for ( ; d < setCount; ++d )
    {
      for ( j = 0; j < obj->m_Tsize; ++j )
        obj->m_data[ t ] = setNew[ j ];
    }
  }
  else
  {
    for ( ; d < setCount; ++d )
    {
      for ( j = 0; j < obj->m_Tsize; ++j )
        obj->m_data[ t ] = 0u;
    }
  }
}
