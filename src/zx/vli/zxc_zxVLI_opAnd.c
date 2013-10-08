#include <zx/vli.h>
/* operator&=  */
ZXCORE_EXP zxVLI* zxc_zxVLI_opAnd( zxVLI *src, zxVLI const *val )
{
  size_t i = 0, j = 0, k = 0,
    end = val->m_bits, stop;
  zxuchr bit = 0u;
  if ( !src || !val )
    return src;
  if ( src->m_bits < end )
    end = src->m_bits;
  stop = end;
	for ( ; stop >= CHAR_BIT; i += CHAR_BIT, ++j )
    src->m_vector.m_data[ j ] &= val->m_vector.m_data[ j ];
  if ( i < end )
  {
    for ( ; i < end; ++i, ++k )
    {
      bit <<= 1;
      bit |= 1u;
    }
    src->m_vector.m_data[ j ] &=
      ( val->m_vector.m_data[ j ] & bit );
    ++j;
    for ( ; k < CHAR_BIT; ++k, ++i );
  }
  for ( ; i < src->m_bits; i += CHAR_BIT, ++j )
    src->m_vector.m_data[ j ] = 0u;
  return src;
}
/* operator&   */
ZXCORE_EXP zxVLI* zxc_zxVLI_cpyAnd( zxVLI *dst, zxVLI const *src, zxVLI const *val )
{
  if ( dst )
  {
    zxvli.cpyEql( dst, src );
    zxvli.opAnd( dst, val );
  }
  return dst;
}