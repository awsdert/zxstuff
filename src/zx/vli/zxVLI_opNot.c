#include <zx/vli.h>
/* operator~=  */
ZXVLI_OPNOT
{
  size_t i = 0, j = 0, stop = zxvli.size( src );
  zxuc bit = 0u, *SRC;
  ZXASSERT( !src )
    return src;
  SRC = src->m_data;
  for ( ; j < stop; i += CHAR_BIT, ++j )
    SRC[ j ] = ~SRC[ j ];
  if ( i < src->m_bits )
  {
    for ( ; i < src->m_bits; ++i )
    {
      bit <<= 1;
      bit |= 1u;
    }
    SRC[ j ] = ~SRC[ j ];
    SRC[ j ] &= bit;
  }
  if ( src->m_isSigned )
    SRC[ src->m_lastByte ] |= src->m_lastBit;
  return src;
}
/* operator~   */
ZXVLI_CPYNOT
{
  if ( dst )
  {
    zxvli.opEql( dst, src );
    zxvli.opNot( dst );
  }
  return dst;
}
#if ZXCPP
zxVli zxVli::operator~( void )
{
  zxVli cpy = *this;
  zxvli.opNot( &cpy );
  return cpy;
}
#endif
