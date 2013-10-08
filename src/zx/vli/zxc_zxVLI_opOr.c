#include <zx/vli.h>
/* operator|=  */
ZXCORE_EXP zxVLI* zxc_zxVLI_opOr( zxVLI *src, zxVLI const *val )
{
  size_t i = 0, j = 0,
    end = val->m_bits, stop = val->m_vector.m_size;
  zxuchr bit = 0u;
  if ( !src || !val )
    return src;
  if ( src->m_bits < end )
    end = src->m_bits;
  stop = end;
	for ( ; stop >= CHAR_BIT; i += CHAR_BIT, ++j, stop -= CHAR_BIT )
    src->m_vector.m_data[ j ] |= val->m_vector.m_data[ j ];
  if ( i < end )
  {
    for ( ; i < end; ++i )
    {
      bit <<= 1;
      bit |= 1u;
    }
    src->m_vector.m_data[ j ] |= val->m_vector.m_data[ j ];
    src->m_vector.m_data[ j ] &= bit;
  }
  if ( src->m_isSigned )
    src->m_vector.m_data[ src->m_lastByte ] |= src->m_lastBit;
  return src;
}
/* operator|   */
ZXCORE_EXP zxVLI* zxc_zxVLI_cpyOr( zxVLI *dst, zxVLI const *src, zxVLI const *val )
{
  if ( dst )
  {
    zxvli.cpyEql( dst, src );
    zxvli.opOr( dst, val );
  }
  return dst;
}