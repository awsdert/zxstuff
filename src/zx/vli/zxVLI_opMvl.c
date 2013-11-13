#include <zx/vli.h>
/* operator <<= */
ZXVLI_OPMVL
{
  size_t s = 0, F = 0, T = 0, t = 0;
  zxuc bitl = 1u << ( CHAR_BIT - 1 ), tbit = bitl, fbit = bitl, val = 0,
    *SRC = (zxuc*)src->m_core.m_data;
  if ( !src || !bits )
    return src;
  if ( bits >= src->m_bits )
  {
    mset( SRC, 0, src->m_core.m_size );
    if ( src->m_isSigned )
      SRC[ src->m_lastByte ] = src->m_lastBit;
    return src;
  }
  T = src->m_lastByte;
  F = T;
  for ( ; s < bits; ++s )
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
    if ( SRC[ F ] & fbit )
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
      SRC[ T ] = val;
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
      SRC[ T ] = val;
      ++T;
      tbit = bitl;
      val = 0;
    }
  }
  if ( src->m_isSigned )
    SRC[ src->m_lastByte ] |= src->m_lastBit;
  return src;
}
/* operator<<  */
ZXVLI_CPYMVL
{
  if ( dst )
  {
    zxvli.opEql( dst, src );
    zxvli.opMvl( dst, bits );
  }
  return dst;
}
