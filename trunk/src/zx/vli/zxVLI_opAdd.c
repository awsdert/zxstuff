#include <zx/vli.h>
/* operator+=  */
ZXVLI_OPADD
{
  zxuc
    cBit = 0u,
    vBit = 1u,
    *SRC = (zxuc*)src->m_core.m_data,
    *VAL = (zxuc*)src->m_core.m_data;
  size_t
    V = 0,
    v = 0,
    end = val->m_bits;
  if ( !src || !val )
    return src;
  if ( src->m_bits < val->m_bits )
    end = src->m_bits;
  for ( ; v < end; ++v )
  {
    if ( cBit > 0u )
    {
      if ( SRC[ V ] & cBit )
        SRC[ V ] &= ~cBit;
      else
      {
        SRC[ V ] |= cBit;
        cBit = 0u;
      }
    }
    if ( VAL[ V ] & vBit )
    {
      if ( SRC[ V ] & vBit )
      {
        SRC[ V ] &= ~vBit;
        cBit = vBit;
      }
      else
        SRC[ V ] |= vBit;
    }
    vBit <<= 1u;
    if ( cBit > 0u )
    {
      cBit <<= 1u;
      if ( cBit == 0u )
        cBit = 1u;
    }
    if ( vBit == 0u )
    {
      ++V;
      vBit = 1u;
    }
  }
  for ( ; ( v < src->m_bits && cBit > 0u ); ++v )
  {
    if ( SRC[ V ] & cBit )
    {
      SRC[ V ] &= ~cBit;
      cBit <<= 1u;
      if ( cBit == 0u )
      {
        cBit = 1u;
        ++V;
      }
    }
    else
    {
      SRC[ V ] |= cBit;
      cBit = 0u;
    }
  }
  return src;
}
ZXVLI_CPYADD
{
  if ( dst )
  {
    zxvli.opEql( dst, src );
    zxvli.opAdd( dst, val );
  }
  return dst;
}
#if ZXCPP
zxVli& zxVli::operator++( void )
{
  zxVlu val = 1u;
  val.m_bits = 1u;
  zxvli.opAdd( this, &val );
  return *this;
}
zxVli  zxVli::operator++( int ignored )
{
  zxVli cpy = *this;
  zxVlu val = 1u;
  val.m_bits = 1u;
  zxvli.opAdd( &cpy, &val );
  return cpy;
}
zxVli  zxVli::operator+( zxVli val )
{
  zxVli cpy = *this;
  zxvli.opAdd( &cpy, &val );
  return cpy;
}
zxVli& zxVli::operator+=( zxVli val )
{
  zxvli.opAdd( this, &val );
  return *this;
}
#endif
