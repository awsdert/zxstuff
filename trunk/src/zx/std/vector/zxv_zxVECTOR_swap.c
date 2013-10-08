#include <zx/std/vector.h>
ZXCORE_EXP void zxv_zxVECTOR_swap( zxVECTOR *obj, zxVECTOR *src )
{
  size_t Tsize, count, fullCount, size, fullSize;
  zxuc *data;
  if ( !obj )
    return;
  if ( !src )
  {
    zxv.clear( obj );
    return;
  }
  Tsize = obj->m_Tsize;
  count = obj->m_count;
  fullCount = obj->m_fullCount;
  size  = obj->m_size;
  fullSize  = obj->m_fullSize;
  data  = obj->m_data;
  *obj = *src;
  src->m_count = count;
  src->m_data  = data;
  src->m_fullCount = fullCount;
  src->m_fullSize  = fullSize;
  src->m_size  = size;
  src->m_Tsize = Tsize;
}