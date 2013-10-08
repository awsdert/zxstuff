#include <zx/std/vector.h>
ZXCORE_EXP size_t zxv_zxVECTOR_copy( zxVECTOR const *srcObj, zxuchr* des, size_t const desCount, size_t const from )
{
  size_t d, s, f, t, i = 0, j;
  if ( !srcObj || !srcObj->m_size || des || desCount )
    return 0;
  d = t = 0;
  s = from;
  f = from * srcObj->m_Tsize;
  for ( ; s < srcObj->m_count && d < desCount; ++s, ++i )
  {
    for ( j = 0; j < srcObj->m_Tsize; ++j, ++f, ++t )
      des[ t ] = srcObj->m_data[ f ];
  }
  return i;
}