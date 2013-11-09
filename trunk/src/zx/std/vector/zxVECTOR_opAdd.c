#include <zx/std/vector.h>
ZXV_OPADD( zxVECTOR, ZXCORE_EXP )
{
  zxv.append( src, cpy, -1 );
  return src;
}
