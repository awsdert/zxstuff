#include <zx/std/vector.h>
ZXCORE_EXP zxVECTOR* zxv_zxVECTOR_cpyEql( zxVECTOR *obj, zxVECTOR const *src )
{
  if ( obj )
  {
    zxv._kill( obj );
    if ( src )
    {
      *obj = *src;
      obj->m_data = (zxuc*)malloc( src->m_fullSize );
      memcpy( obj->m_data, src->m_data, src->m_fullSize );
    }
  }
  return obj;
}