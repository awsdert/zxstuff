#include <zx/std/math.h>
ZXCORE_EXP void zxm_i2s( zxui value, zxus* dst, zxuc i )
{
  zxus tmp[2] = { 0, 0 };
#if ZXINT_BITS <= ZXSHORT_BITS
  tmp[ 0 ] = value;
#else
  zxus *val = (zxus*)&value;
  switch ( ((zxus*)&zxm_test_i)[0] )
  {
  case 0x1234:
    tmp[ 0 ] = val[ 1 ];
    tmp[ 1 ] = val[ 0 ];
    break;
  default:
    tmp[ 0 ] = val[ 0 ];
    tmp[ 1 ] = val[ 1 ];
  }
#endif
  *dst = tmp[ i ];
}
