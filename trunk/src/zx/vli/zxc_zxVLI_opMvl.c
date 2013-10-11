#include <zx/vli.h>
/* operator <<= */
ZXCORE_EXP zxVLI* zxc_zxVLI_opMvl( zxVLI* src, size_t by )
{
  size_t s = 0, F = 0, T = 0, t = 0;
  zxuchr bitl = 1u << ( CHAR_BIT - 1 ), tbit = bitl, fbit = bitl, val = 0;
  if ( !src || !by )
    return src;
  if ( by >= src->m_bits )
  {
    memset( src->m_vector.m_data, 0, src->m_vector.m_size );
    if ( src->m_isSigned )
      src->m_vector.m_data[ src->m_lastByte ] = src->m_lastBit;
    return src;
  }
  T = src->m_lastByte;
  F = T;
  for ( ; s < by; ++s )
  {
    fbit >>= 1;
    if ( !fbit )
    {
      --F;
      fbit = bitl;
    }
  }
  for ( ; s < src->m_bits; ++s, ++t )
  {
    if ( src->m_vector.m_data[ F ] & fbit )
      val |= tbit;
    fbit >>= 1;
    if ( !fbit )
    {
      --F;
      fbit = bitl;
    }
    tbit >>= 1;
    if ( !tbit )
    {
      src->m_vector.m_data[ T ] = val;
      --T;
      tbit = bitl;
      val = 0;
    }
  }
  for ( ; t < src->m_bits; ++t )
  {
    tbit >>= 1;
    if ( !tbit )
    {
      src->m_vector.m_data[ T ] = val;
      ++T;
      tbit = bitl;
      val = 0;
    }
  }
  if ( src->m_isSigned )
    src->m_vector.m_data[ src->m_lastByte ] |= src->m_lastBit;
  return src;
}
/* operator<<  */
ZXCORE_EXP zxVLI* zxc_zxVLI_cpyMvl( zxVLI *dst, zxVLI const *src, size_t by )
{
  if ( dst )
  {
    zxvli.cpyEql( dst, src );
    zxvli.opMvl( dst, by );
  }
  return dst;
}