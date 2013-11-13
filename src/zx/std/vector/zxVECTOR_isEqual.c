#include <zx/std/vector.h>
ZXCORE bool zxVECTOR_isEqual( zxVECTOR const *vec, zxVECTOR const *cmp, size_t* i )
{
  size_t cs = 0, c = 0, j = 0, k, m;
  zxuc *VEC, *CMP;
  if ( i )
    *i = SIZE_MAX;
  if ( vec == cmp )
    return true;
  ZXASSERT( !vec || !cmp )
    return false;
  VEC = (zxuc*)vec->m_data;
  CMP = (zxuc*)cmp->m_data;
  cs = vec->m_count;
  c  = cs - 1;
  if ( i )
    *i = c;
  if ( vec->m_count != cmp->m_count ||
    vec->m_size != cmp->m_size ||
    vec->m_Tsize != cmp->m_Tsize )
    return false;
  m = vec->m_size;
  for ( ; c != cs; --c, --cs )
  {
    k = m -= vec->m_Tsize;
    for ( j = 0; j < vec->m_Tsize; ++j, ++k )
    {
      if ( VEC[ k ] != CMP[ k ] )
      {
        if ( i )
          *i = c;
        return false;
      }
    }
  }
  if ( i )
    *i = 0;
  return true;
}
