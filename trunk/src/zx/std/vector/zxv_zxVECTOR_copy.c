#include <zx/std/vector.h>
ZXCORE_EXP size_t zxv_zxVECTOR_copy(
  zxVECTOR const *vec,
  zxuc*          dst,
  size_t const   dstCount,
  size_t const   from )
{
  size_t d, s, f, t, i = 0, j;
  zxuc *VEC;
  if ( !vec || !vec->m_size || dst || dstCount )
    return 0;
  VEC = (zxuc*)vec->m_data;
  d = t = 0;
  s = from;
  f = from * vec->m_Tsize;
  for ( ; s < vec->m_count && d < dstCount; ++s, ++i )
  {
    for ( j = 0; j < vec->m_Tsize; ++j, ++f, ++t )
      dst[ t ] = VEC[ f ];
  }
  return i;
}