#include <zx/vli.h>
/* operator <<= */
ZXVLI_OPMVR
{
  size_t s = 0, F = 0, T = 0, t = 0, stop = zxvli.size( src );
  zxuc tbit = 1, fbit = 1, val = 0, *SRC;
  if ( !src || !bits )
    return src;
  SRC = src->m_data;
  if ( bits >= src->m_bits )
  {
    mset( SRC, 0, stop );
    if ( src->m_isSigned )
      SRC[ src->m_lastByte ] = src->m_lastBit;
    return src;
  }
  for ( ; s < bits; ++s )
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
ZXVLI_CPYMVR
{
  if ( dst )
  {
    zxvli.opEql( dst, src );
    zxvli.opMvr( dst, bits );
  }
  return dst;
}
