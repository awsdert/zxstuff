#include <zx/std/vector.h>
ZXCORE_EXP void zxv_zxVECTOR_shrink( zxVECTOR* obj, size_t setCount )
{
  size_t size = 0;
  ZXASSERT( !obj )
    return;
  if ( !obj->m_data || !obj->m_Tsize || setCount >= obj->m_fullCount )
    return;
  if ( setCount )
  {
    size = setCount * obj->m_Tsize;
    obj->m_data = (zxuchr*)realloc( obj->m_data, size );
  }
  else
  {
    free( obj->m_data );
    obj->m_data = NULL;
  }
  obj->m_size      = size;
  obj->m_fullSize  = size;
  obj->m_count     = setCount;
  obj->m_fullCount = setCount;
}