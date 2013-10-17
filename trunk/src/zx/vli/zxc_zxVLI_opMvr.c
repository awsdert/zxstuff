#include <zx/vli.h>
/* operator <<= */
ZXCORE_EXP zxVLI* zxc_zxVLI_opMvr( zxVLI* src, size_t by )
{
  size_t s = 0, F = 0, T = 0, t = 0;
  zxuc tbit = 1, fbit = 1, val = 0,
    *SRC = (zxuc*)src->m_vector.m_data;
  if ( !src || !by )
    return src;
  if ( by >= src->m_bits )
  {
    mset( SRC, 0, src->m_vector.m_size );
    if ( src->m_isSigned )
      SRC[ src->m_lastByte ] = src->m_lastBit;
    return src;
  }
  for ( ; s < by; ++s )
  {
    fbit <<= 1;
    if ( !fbit )
    {
      ++F;
      fbit = 1;
    }
  }
  for ( ; s < src->m_bits; ++s, ++t )
  {
    if ( SRC[ F ] & fbit )
      val |= tbit;
    fbit <<= 1;
    if ( !fbit )
    {
      ++F;
      fbit = 1;
    }
    tbit <<= 1;
    if ( !tbit )
    {
      SRC[ T ] = val;
      ++T;
      tbit = 1;
      val = 0;
    }
  }
  for ( ; t < src->m_bits; ++t )
  {
    tbit <<= 1;
    if ( !tbit )
    {
      SRC[ T ] = val;
      ++T;
      tbit = 1;
      val = 0;
    }
  }
  if ( src->m_isSigned )
    SRC[ src->m_lastByte ] |= src->m_lastBit;
  return src;
}
/* operator<<  */
ZXCORE_EXP zxVLI* zxc_zxVLI_cpyMvr( zxVLI *dst, zxVLI const *src, size_t by )
{
  if ( dst )
  {
    zxvli.cpyEql( dst, src );
    zxvli.opMvr( dst, by );
  }
  return dst;
}
