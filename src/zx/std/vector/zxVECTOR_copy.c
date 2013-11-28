#include <zx/std/vector.h>
ZXV_COPY( zxVECTOR, void, ZXCORE, ZXCORE_CALL )
{
  size_t to, size;
  zxuc *SRC;
  if ( !src || !src->m_data || !dst || !count || from >= src->m_count )
    return 0;
  SRC = (zxuc*)src->m_data;
  to = from + count;
  if ( to >= src->m_count )
    to = src->m_count - 1;
  size = to - from;
  mcpy( dst, &SRC[ from * src->m_Tsize ], size * src->m_Tsize );
  return size;
}
