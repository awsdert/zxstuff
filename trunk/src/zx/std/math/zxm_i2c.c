#include <zx/std/math.h>
ZXCORE_EXP void zxm_i2c( zxui value, zxuc* dst, zxuc i )
{
  zxuc tmp[ 4 ] = {0,0,0,0};
#if ZXINT_BITS <= CHAR_BIT
  tmp[ 0 ] = value;
#else
  zxuc *val = (zxuc*)&value;
  switch ( ((zxuc*)&zxm_test_i)[0] )
  {
  case 0x12:
    tmp[ 0 ] = val[ 3 ];
    tmp[ 1 ] = val[ 2 ];
    tmp[ 2 ] = val[ 1 ];
    tmp[ 3 ] = val[ 0 ];
    break;
  case 0x34:
    tmp[ 0 ] = val[ 2 ];
    tmp[ 1 ] = val[ 3 ];
    tmp[ 2 ] = val[ 0 ];
    tmp[ 3 ] = val[ 1 ];
    break;
  case 0x56:
    tmp[ 0 ] = val[ 1 ];
    tmp[ 1 ] = val[ 0 ];
    tmp[ 2 ] = val[ 3 ];
    tmp[ 3 ] = val[ 2 ];
  default:
    tmp[ 0 ] = val[ 0 ];
    tmp[ 1 ] = val[ 1 ];
    tmp[ 2 ] = val[ 2 ];
    tmp[ 3 ] = val[ 3 ];
  }
#endif
  *dst = tmp[ i ];
}
