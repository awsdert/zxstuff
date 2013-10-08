#include <zx/vli.h>
/* operator~=  */
ZXCORE_EXP zxVLI* zxc_zxVLI_opNot( zxVLI* src )
{
  size_t i = 0, j = 0;
  zxuchr bit = 0u;
  if ( !src )
    return src;
  for ( ; j < src->m_vector.m_size; i += CHAR_BIT, ++j )
    src->m_vector.m_data[ j ] = ~src->m_vector.m_data[ j ];
  if ( i < src->m_bits )
  {
    for ( ; i < src->m_bits; ++i )
    {
      bit <<= 1;
      bit |= 1u;
    }
    src->m_vector.m_data[ j ] = ~src->m_vector.m_data[ j ];
    src->m_vector.m_data[ j ] &= bit;
  }
  if ( src->m_isSigned )
    src->m_vector.m_data[ src->m_lastByte ] |= src->m_lastBit;
  return src;
}
/* operator~   */
ZXCORE_EXP zxVLI* zxc_zxVLI_cpyNot( zxVLI *dst, zxVLI const *src )
{
  if ( dst )
  {
    zxvli.cpyEql( dst, src );
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