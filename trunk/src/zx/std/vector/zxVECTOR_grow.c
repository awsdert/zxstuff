#include <zx/std/vector.h>
ZXV_GROW( zxVECTOR, void*, ZXCORE, ZXCORE_CALL )
{
  size_t d, t, size;
  zxuc *SRC;
  ZXASSERT( !src )
    return;
  if ( src->m_isFixed || setCount <= src->m_count )
    return;
  size = setCount * src->m_Tsize;
  src->m_data = realloc( src->m_data, size );
  SRC = (zxuc*)src->m_data;
  d = src->m_count;
  t = src->m_size;
  if ( setNew )
  {
    for ( ; d < setCount; ++d, t += src->m_Tsize )
      mcpy( &SRC[ t ], setNew, src->m_Tsize );
  }
  else
  {
    for ( ; d < setCount; ++d, t += src->m_Tsize )
      mset( &SRC[ t ], 0, src->m_Tsize );
  }
  if ( src->m_ptr )
    *src->m_ptr = src->m_data;
  src->m_count = d;
  if ( d > src->m_fullCount )
    src->m_fullCount = d;
  src->m_size  = t;
  if ( t > src->m_fullSize )
    src->m_fullSize = t;
}
