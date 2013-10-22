#include <zx/std/vector.h>
ZXV_GROW( zxVECTOR, zxuc*, ZXCORE_EXP )
{
  size_t d, t, j, size;
  zxuc *des;
  ZXASSERT( !src )
    return;
  if ( src->m_isFixed || setCount <= src->m_count )
    return;
  size = setCount++ * src->m_Tsize;
  src->m_data = realloc( src->m_data, size );
  des = (zxuc*)src->m_data;
  d = src->m_count;
  t = src->m_size;
  if ( setNew )
  {
    for ( ; d < setCount; ++d )
    {
      for ( j = 0; j < src->m_Tsize; ++j )
        des[ t ] = setNew[ j ];
    }
  }
  else
  {
    for ( ; d < setCount; ++d )
    {
      for ( j = 0; j < src->m_Tsize; ++j )
        des[ t ] = 0u;
    }
  }
  if ( src->m_ptr )
    *src->m_ptr = src->m_data;
}
