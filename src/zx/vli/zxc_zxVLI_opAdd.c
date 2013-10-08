#include <zx/vli.h>
/* operator+=  */
ZXCORE_EXP zxVLI* zxc_zxVLI_opAdd( zxVLI *src, zxVLI const *val )
{
  zxuchr
    cBit = 0u,
    vBit = 1u;
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
      if ( src->m_vector.m_data[ V ] & cBit )
        src->m_vector.m_data[ V ] &= ~cBit;
      else
      {
        src->m_vector.m_data[ V ] |= cBit;
        cBit = 0u;
      }
    }
    if ( val->m_vector.m_data[ V ] & vBit )
    {
      if ( src->m_vector.m_data[ V ] & vBit )
      {
        src->m_vector.m_data[ V ] &= ~vBit;
        cBit = vBit;
      }
      else
        src->m_vector.m_data[ V ] |= vBit;
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
    if ( src->m_vector.m_data[ V ] & cBit )
    {
      src->m_vector.m_data[ V ] &= ~cBit;
      cBit <<= 1u;
      if ( cBit == 0u )
      {
        cBit = 1u;
        ++V;
      }
    }
    else
    {
      src->m_vector.m_data[ V ] |= cBit;
      cBit = 0u;
    }
  }
  return src;
}
ZXCORE_EXP zxVLI* zxc_zxVLI_cpyAdd( zxVLI *dst, zxVLI const *src, zxVLI const *val )
{
  if ( dst )
  {
    zxvli.cpyEql( dst, src );
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