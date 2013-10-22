#include <zx/std/char.h>
ZXCORE_EXP zxumax zxv_zxCHAR_2UI( zxCHAR const *txt, zxuc base )
{
  size_t i = 0u, len;
  char const *cmp = zx___cBase;
  zxuc b;
  zxumax val = 0u;
  if ( !txt || base < 2u || base > zx___baseLen )
    return 0u;
  len = zxc.size( txt );
  if ( !len )
    len = zxc.len( txt->m_data );
  for ( ; i < len && val < zx___baseMax[ base ]; ++i )
  {
    for ( b = 0u; b < base; ++b )
    {
      if ( txt->m_data[ i ] == cmp[ b ] )
      {
        val *= b;
        val += b;
      }
    }
  }
  return val;
}
ZXCORE_EXP zxsmax zx_c2i( zxCHAR const *txt, zxuchr base )
{
  if ( !txt )
    return 0;
  if ( txt->m_data[ 0 ] == '-' )
    return (zxsmax)zxv_zxCHAR_2UI( txt, base ) * -1;
  else
    return (zxsmax)zxv_zxCHAR_2UI( txt, base );
}