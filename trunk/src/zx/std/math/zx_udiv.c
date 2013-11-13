#include <zx/std/math.h>
ZXCORE ZX__UDIV_SRC( imax,   ZXIMAX )
size_t zxc_size_udiv( size_t src, size_t val, size_t *remainder ) { \
  size_t i = zxc_size_LastBitI;
  size_t des = 0u, quo = 0u, bit = zxc_size_LastBit, rem = 0u;
  if ( remainder )
    *remainder = 0u;
  if ( !src )
    return 0u;
  if ( !val )
    return 0u;
  for ( ; bit != 0u && src >= val; bit >>= 1, --i )
  {
    des <<= 1;
    quo <<= 1;
    rem |= bit;
    if ( src & bit )
      des |= 1u;
    if ( des >= val )
    {
      des -= val;
      quo |= 1u;
      src ^= rem;
      src |= ( des << i );
    }
  }
  if ( remainder )
    *remainder = quo;
  return des;
}
ZXCORE zxsm zx_imax_sdiv(  zxsm src, zxsm value, zxsm *remainder )
{
  zxsm rem = 0;
  bool sneg = ( src < 0 ), vneg = ( value < 0 );
  if ( sneg )
    src = ~( src );
  if ( vneg )
    value = ~value;
  src = (zxsm)zx_imax_udiv( (zxum)src, (zxum)value, (zxum*)remainder );
  if ( sneg )
  {
    rem = ~rem;
    if ( vneg )
      return ~( src );
  }
  else if ( vneg )
    return ~( src );
  return src;
}
