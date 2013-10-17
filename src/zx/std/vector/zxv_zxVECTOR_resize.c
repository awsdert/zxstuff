#include <zx/std/vector.h>
ZXCORE_EXP void zxv_zxVECTOR_resize(
  zxVECTOR       *obj,
  size_t   const setCount,
  zxuc     const *setNew )
{
  ZXASSERT( !obj )
    return;
  if ( setCount == obj->m_count ) return;
  if ( setCount < obj->m_count )
  {
    zxv.erase( obj, setCount, obj->m_count );
    return;
  }
  zxv.grow( obj, setCount, setNew );
}