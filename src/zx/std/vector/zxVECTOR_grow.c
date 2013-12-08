#include <zx/std/vector.h>
ZXV_GROW( zxVECTOR, void*, ZXCORE, ZXCORE_CALL )
{
  size_t i, t, size;
  zxuc *SRC;
  ZXASSERT( !src )
    return;
  if ( src->m_isFixed || setCount <= src->m_count )
    return;
  size = setCount * src->m_Tsize;
  if ( setCount > src->m_fullCount )
  {
    src->m_data = realloc( src->m_data, size );
    if ( !src->m_data )
    {
      setCount = 0;
      size     = 0;
    }
    src->m_fullCount = setCount;
    src->m_fullSize = size;
  }
  SRC = (zxuc*)src->m_data;
  i = src->m_count;
  t = src->m_size;
  if ( setNew )
  {
    for ( ; i < setCount; ++i, t += src->m_Tsize )
      mcpy( &SRC[ t ], setNew, src->m_Tsize );
  }
  else
  {
    for ( ; i < setCount; ++i, t += src->m_Tsize )
      mset( &SRC[ t ], 0, src->m_Tsize );
  }
  if ( src->m_ptr )
    *src->m_ptr = src->m_data;
  src->m_count = setCount;
  src->m_size  = size;
}
