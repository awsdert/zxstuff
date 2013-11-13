#include <zx/std/vector.h>
ZXV_SHRINK( zxVECTOR, ZXCORE, ZXCORE_CALL )
{
  size_t size = 0;
  ZXASSERT( !src )
    return;
  if ( src->m_isFixed || !src->m_data || !src->m_Tsize || setCount >= src->m_count )
    return;
  if ( setCount )
  {
    size = setCount * src->m_Tsize;
    src->m_data = realloc( src->m_data, size );
  }
  else
  {
    free( src->m_data );
    src->m_data = NULL;
  }
  if ( src->m_ptr )
    *src->m_ptr = src->m_data;
  src->m_size      = size;
  src->m_fullSize  = size;
  src->m_count     = setCount;
  src->m_fullCount = setCount;
}
