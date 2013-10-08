#include <zx/std/vector.h>
ZXCORE_EXP void zxv_zxVECTOR_insert(
  zxVECTOR       *obj,
  zxVECTOR const *src,
  size_t          pos )
{
  size_t d, s, i, j, f, t, stop;
  if ( !obj || !src ||
    !src->m_data || !src->m_count ||
    !src->m_size ) return;
  i = obj->m_count;
  s = i - 1;
  f = obj->m_size - 1;
  stop = obj->m_Tsize;
  if ( src->m_Tsize < stop )
    stop = src->m_Tsize;
  zxv.resize( obj, i + src->m_count, NULL );
  d = obj->m_count - 1;
  t = obj->m_size  - 1;
  --pos;
  for ( ; i != s && s >= pos; --i, --s, --d )
  {
    for ( j = 0; j < obj->m_Tsize; ++j, --f, --t )
      obj->m_data[ t ] = obj->m_data[ f ];
  }
  i = d + 1;
  s = src->m_count - 1;
  f = src->m_size  - 1;
  for ( ; i != d && d >= pos; --d, --s, --i )
  {
    for ( j = 0; j < stop; ++j, --f, --t )
      obj->m_data[ t ] = src->m_data[ f ];
    for ( ; j < obj->m_Tsize; ++j, --f, --t )
      obj->m_data[ t ] = 0u;
  }
}