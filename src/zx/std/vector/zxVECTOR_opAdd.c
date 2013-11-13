#include <zx/std/vector.h>
ZXV_OPADD( zxVECTOR, ZXCORE, ZXCORE_CALL )
{
  zxv.append( src, cpy, -1 );
  return src;
}
