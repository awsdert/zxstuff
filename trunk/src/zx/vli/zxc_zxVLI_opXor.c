#include <zx/vli.h>
/* operator^=  */
ZXCORE_EXP zxVLI* zxc_zxVLI_opXor( zxVLI *src, zxVLI const *val )
{
  size_t i = 0, j = 0,
    end = val->m_bits, stop = val->m_vector.m_size;
  zxuc bit = 0u,
    *SRC = (zxuc*)src->m_vector.m_data,
    *VAL = (zxuc*)val->m_vector.m_data;
  if ( !src || !val )
    return src;
  if ( src->m_bits < end )
    end = src->m_bits;
  stop = end;
	for ( ; stop >= CHAR_BIT; i += CHAR_BIT, ++j, stop -= CHAR_BIT )
    SRC[ j ] ^= VAL[ j ];
  if ( i < end )
  {
    for ( ; i < end; ++i )
    {
      bit <<= 1;
      bit |= 1u;
    }
    SRC[ j ] ^= VAL[ j ];
    SRC[ j ] &= bit;
  }
  if ( src->m_isSigned )
    SRC[ src->m_lastByte ] |= src->m_lastBit;
  return src;
}
/* operator^   */
ZXCORE_EXP zxVLI* zxc_zxVLI_cpyXor( zxVLI *dst, zxVLI const *src, zxVLI const *val )
{
  if ( dst )
  {
    zxvli.cpyEql( dst, src );
    zxvli.opXor( dst, val );
  }
  return dst;
}