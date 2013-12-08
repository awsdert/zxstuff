#include <zx/std/vector.h>
ZXV_ISEQUAL( zxVECTOR, ZXCORE, ZXCORE_CALL )
{
  size_t k = 0;
  if ( I )
    *I = UINT_MAX;
  if ( src == cmp )
    return true;
  ZXASSERT( !src || !cmp )
    return false;
  if ( I )
    *I = src->m_count - 1;
  if ( src->m_count != cmp->m_count ||
    src->m_size != cmp->m_size ||
    src->m_Tsize != cmp->m_Tsize )
    return false;
  if ( !mcmp( src->m_data, cmp->m_data, src->m_size, &k ) )
  {
    if ( I )
      *I = ( k / src->m_Tsize ) & UINT_MAX;
    return false;
  }
  if ( I )
    *I = 0;
  return true;
}
