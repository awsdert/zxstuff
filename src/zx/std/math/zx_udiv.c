#include <zx/std/math.h>
ZXM__UDIV( imax, ZXIMAX, ZXCORE, ZXCORE_CALL )
{
  zxum i = zxm_imax_LastBit,
    des = 0u,
    quo = 0,
    bit = zxm_imax_LastBit,
    rem = 0u;
  if ( !src || !val )
  {
    if ( remainder )
      *remainder = 0u;
    return 0;
  }
  if ( src < val )
  {
    if ( remainder )
      *remainder = val;
    return 0;
  }
  do
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
    --i; bit >>= 1;
  }
  while ( bit != 0 && src >= val );
  if ( remainder )
    *remainder = quo;
  return des;
}

ZXM_DEC_UDIV( int,    int,         ZXCORE, ZXCORE_CALL, ZXUINT_MAX  )
ZXM_DEC_UDIV( short,  short,       ZXCORE, ZXCORE_CALL, ZXUSHRT_MAX )
ZXM_DEC_UDIV( size,   ZXSIZE_TYPE, ZXCORE, ZXCORE_CALL, ZXSIZE_MAX  )
ZXM_DEC_UDIV( char,   char,        ZXCORE, ZXCORE_CALL, ZXUCHAR_MAX )
ZXM_DEC_UDIV( long,   long,        ZXCORE, ZXCORE_CALL, ZXULONG_MAX )
#ifdef ZXILL
ZXM_DEC_UDIV( ill,    ZXILL,       ZXCORE, ZXCORE_CALL, ZXUILL_MAX  )
#endif

ZXM__SDIV( imax, ZXIMAX, ZXCORE, ZXCORE_CALL )
{
  zxsm rem = 0;
  bool sneg = ( src < 0 ), vneg = ( val < 0 );
  if ( sneg )
    src = ~( src );
  if ( vneg )
    val *= -1;
  src = (zxsm)zxdivu_imax( (zxum)src, (zxum)val, (zxum*)remainder );
  if ( sneg )
  {
    rem *= -1;
    if ( vneg )
      return src * -1;
  }
  else if ( vneg )
    return src * -1;
  return src;
}
