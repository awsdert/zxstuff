#include <zx/std/vector.h>
ZXCORE_EXP void zxv_zxVECTOR_erase( zxVECTOR *vec, size_t first, size_t last )
{
  size_t i, s, d, f = 0, t, j;
  zxuc *VEC;
  if ( !vec ) return;
  VEC = (zxuc*)vec->m_data;
  d = first;
  if ( !d ) t = 0;
  else t = d * vec->m_Tsize;
  if ( !last )
  {
    s = d + 1;
    i = vec->m_count - 1;
    f = t + vec->m_Tsize;
  }
  else if ( last >= vec->m_count )
  {
    s = vec->m_count;
    i = vec->m_count - (s - d);
  }
  else
  {
    i = ++last - d;
    s = last;
    i = vec->m_count - i;
    f = s * vec->m_Tsize;
  }
  for ( ; s < vec->m_count; ++s, ++d )
  {
    for ( j = 0; j < vec->m_Tsize; ++j, ++f, ++t )
      VEC[ t ] = VEC[ f ];
  }
  for ( ; d < vec->m_count; ++d )
  {
    for ( j = 0; j < vec->m_Tsize; ++j, ++t )
      VEC[ t ] = 0u;
  }
  vec->m_count = i;
  vec->m_size  = i * vec->m_Tsize;
}
