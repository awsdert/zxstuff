#include <zx/std/vector.h>
ZXCORE_EXP bool zxv_zxVECTOR_isEqual( zxVECTOR const *obj, zxVECTOR const *cmp, size_t* i )
{
  size_t cs = 0, c = 0, j = 0, k, m;
  if ( i )
    *i = SIZE_MAX;
  if ( obj == cmp )
    return true;
  if ( !obj )
  {
    assert( !obj );
    return false;
  }
  if ( !cmp )
  {
    assert( !cmp );
    return false;
  }
  cs = obj->m_count;
  c  = cs - 1;
  if ( i )
    *i = c;
  if ( obj->m_count != cmp->m_count || obj->m_size != cmp->m_size || obj->m_Tsize != cmp->m_Tsize )
    return false;
  m = obj->m_size;
  for ( ; c != cs; --c, --cs )
  {
    k = m -= obj->m_Tsize;
    for ( j = 0; j < obj->m_Tsize; ++j, ++k )
    {
      if ( obj->m_data[ k ] != cmp->m_data[ k ] )
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