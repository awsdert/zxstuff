#include <zx/std/vector.h>
ZXCORE_EXP bool zxv_zxVECTOR_push_back(
  zxVECTOR *vec,
  zxVECTOR const *src )
{
  size_t i, j = 0, stop;
  zxuc *VEC, *SRC;
  ZXASSERT( !vec || !src )
    return false;
  i = vec->m_count;
  stop = i + src->m_count;
  zxv.grow( vec, vec->m_count + src->m_count, NULL );
  VEC = (zxuc*)vec->m_data;
  SRC = (zxuc*)src->m_data;
  for ( ; i < stop; ++i, ++j )
    VEC[ i ] = SRC[ j ];
  return true;
}