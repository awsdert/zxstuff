#include <zx/vli.h>
/* operator|=  */
ZXVLI_OPOR
{
  size_t i = 0, j = 0,
    end = val->m_bits, stop = zxvli.size( val );
  zxuc bit = 0u,
    *SRC = src->m_data,
    *VAL = val->m_data;
  if ( !src || !val )
    return src;
  if ( src->m_bits < end )
    end = src->m_bits;
  stop = end;
  for ( ; stop >= CHAR_BIT; i += CHAR_BIT, ++j, stop -= CHAR_BIT )
    SRC[ j ] |= VAL[ j ];
  if ( i < end )
  {
    for ( ; i < end; ++i )
    {
      bit <<= 1;
      bit |= 1u;
    }
    SRC[ j ] |= VAL[ j ];
    SRC[ j ] &= bit;
  }
  if ( src->m_isSigned )
    SRC[ src->m_lastByte ] |= src->m_lastBit;
  return src;
}
/* operator|   */
ZXVLI_CPYOR
{
  if ( dst )
  {
    zxvli.opEql( dst, src );
    zxvli.opOr( dst, val );
  }
  return dst;
}
