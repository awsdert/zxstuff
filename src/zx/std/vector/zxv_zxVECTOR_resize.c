#include <zx/std/vector.h>
ZXCORE_EXP void zxv_zxVECTOR_resize( zxVECTOR *obj, size_t setCount, zxuchr const *setNew )
{
  if ( !obj )
  {
    assert( !obj );
    return;
  }
  if ( setCount == obj->m_count ) return;
  if ( setCount < obj->m_count )
  {
    zxv.erase( obj, setCount, obj->m_count );
    return;
  }
  zxv.grow( obj, setCount, setNew );
}