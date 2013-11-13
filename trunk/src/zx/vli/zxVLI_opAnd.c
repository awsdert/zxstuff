#include <zx/vli.h>
/* operator&=  */
ZXVLI_OPAND
{
  size_t i = 0, j = 0, k = 0,
    end = val->m_bits, stop;
  zxuc bit = 0u,
    *SRC = (zxuc*)src->m_core.m_data,
    *VAL = (zxuc*)val->m_core.m_data;
  if ( !src || !val )
    return src;
  if ( src->m_bits < end )
    end = src->m_bits;
  stop = end;
  for ( ; stop >= CHAR_BIT; i += CHAR_BIT, ++j )
    SRC[ j ] &= VAL[ j ];
  if ( i < end )
  {
    for ( ; i < end; ++i, ++k )
    {
      bit <<= 1;
      bit |= 1u;
    }
    SRC[ j ] &=
      ( VAL[ j ] & bit );
    ++j;
    for ( ; k < CHAR_BIT; ++k, ++i );
  }
  for ( ; i < src->m_bits; i += CHAR_BIT, ++j )
    SRC[ j ] = 0u;
  return src;
}
/* operator&   */
ZXVLI_CPYAND
{
  if ( dst )
  {
    zxvli.opEql( dst, src );
    zxvli.opAnd( dst, val );
  }
  return dst;
}
