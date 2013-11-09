#include <zx/endian.h>
ZXCORE_EXP zxuc* zxcopy(
  zxuc* src, size_t ssize, zxEndian sen,
  zxuc* des, size_t dsize, zxEndian den )
{
  size_t i = 0, t,
    end = ssize;
  zxuc *tmp = NULL, val = 0u;
  if ( !dsize )
    return des;
  if ( !des )
    des = (zxuc*)malloc( dsize );
  if ( !src || !ssize )
  {
    for ( ; i < dsize; ++i )
      des[ i ] = 0u;
    return des;
  }
  if ( end > dsize )
    end = dsize;
  if ( sen == den )
  {
    if ( src == des )
      return des;
    for ( ; i < end; ++i )
      des[ i ] = src[ i ];
    if ( (zxsc)( src[ ssize - 1 ] ) < 0 )
      val = UCHAR_MAX;
    for ( ; i < dsize; ++i )
      des[ i ] = val;
    return des;
  }
  tmp = (zxuc*)malloc( dsize );
  switch ( sen )
  {
  case zxENDIAN_BIG:
    for ( ; i < ssize; ++i )
      tmp[ i ] = src[ i ];
    break;
  case zxENDIAN_PDP:
    for ( t = 1; i < ssize; i += 2, t += 2 )
      tmp[ t ] = src[ i ];
    for ( i = 1, t = 0; i < ssize; i += 2, t += 2 )
      tmp[ t ] = src[ i ];
    break;
  case zxENDIAN_LITTLE:
    for ( t = ssize - 1; t >= 0; ++i, --t )
      tmp[ i ] = src[ t ];
    break;
  default:
    for ( ; i < ssize; ++i )
      tmp[ i ] = 0u;
  }
  i = 0;
  switch ( den )
  {
  case zxENDIAN_BIG:
    for ( ; i < end; ++i )
      des[ i ] = tmp[ i ];
    for ( ; i < dsize; ++i )
      des[ i ] = 0u;
    break;
  case zxENDIAN_PDP:
    for ( t = 1; i < end; i += 2, t += 2 )
      des[ t ] = tmp[ i ];
    for ( i = 1, t = 0; i < end; i += 2, t += 2 )
      des[ t ] = tmp[ i ];
    for ( i = end; i < dsize; ++i )
      des[ i ] = 0u;
    break;
  case zxENDIAN_LITTLE:
    for ( t = end - 1; i < end; ++i, --t )
      des[ i ] = tmp[ t ];
    for ( i = dsize - 1; t >= end; --t )
      des[ i ] = 0u;
    break;
  default:
    for ( ; i < dsize; ++i )
      des[ i ] = 0u;
    break;
  }
  free( tmp );
  return des;
}
