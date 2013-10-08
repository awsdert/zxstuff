#include <zx/std/vector.h>
ZXCORE_EXP void zxv_zxVECTOR_erase( zxVECTOR *obj, size_t first, size_t last )
{
  size_t i, s, d, f = 0, t, j;
  if ( !obj ) return;
  d = first;
  if ( !d ) t = 0;
  else t = d * obj->m_Tsize;
  if ( !last )
  {
    s = d + 1;
    i = obj->m_count - 1;
    f = t + obj->m_Tsize;
  }
  else if ( last >= obj->m_count )
  {
    s = obj->m_count;
    i = obj->m_count - (s - d);
  }
  else
  {
    i = ++last - d;
    s = last;
    i = obj->m_count - i;
    f = s * obj->m_Tsize;
  }
  for ( ; s < obj->m_count; ++s, ++d )
  {
    for ( j = 0; j < obj->m_Tsize; ++j, ++f, ++t )
      obj->m_data[ t ] = obj->m_data[ f ];
  }
  for ( ; d < obj->m_count; ++d )
  {
    for ( j = 0; j < obj->m_Tsize; ++j, ++t )
      obj->m_data[ t ] = 0u;
  }
  obj->m_count = i;
  obj->m_size  = i * obj->m_Tsize;
}
