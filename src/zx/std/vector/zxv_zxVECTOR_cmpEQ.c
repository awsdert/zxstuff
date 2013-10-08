#include <zx/std/vector.h>
ZXCORE_EXP bool zxv_zxVECTOR_cmpEQ( zxVECTOR const *obj, zxVECTOR const *cmp )
{
  return zxv.isEqual( obj, cmp, NULL );
}