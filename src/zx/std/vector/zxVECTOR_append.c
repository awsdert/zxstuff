#include <zx/std/vector.h>
ZXCORE_EXP void zxVECTOR_append( zxVECTOR *vec, zxVECTOR const *src, size_t pos )
{
  size_t d, s, i, j, f, t, stop;
  zxuc *VEC, *SRC;
  if ( !vec || !src ||
    !src->m_data || !src->m_count ||
    !src->m_size ) return;
  i = vec->m_count;
  s = i - 1;
  f = vec->m_size - 1;
  stop = vec->m_Tsize;
  if ( src->m_Tsize < stop )
    stop = src->m_Tsize;
  zxv.resize( vec, i + src->m_count, NULL );
  VEC = (zxuc*)vec->m_data;
  SRC = (zxuc*)src->m_data;
  d = vec->m_count - 1;
  t = vec->m_size  - 1;
  ++pos;
  for ( ; i != s && s >= pos; --i, --s, --d )
  {
    for ( j = 0; j < vec->m_Tsize; ++j, --f, --t )
      VEC[ t ] = VEC[ f ];
  }
  i = d + 1;
  s = src->m_count - 1;
  f = src->m_size  - 1;
  for ( ; i != d && d >= pos; --d, --s, --i )
  {
    for ( j = 0; j < stop; ++j, --f, --t )
      VEC[ t ] = SRC[ f ];
    for ( ; j < vec->m_Tsize; ++j, --f, --t )
      VEC[ t ] = 0u;
  }
}