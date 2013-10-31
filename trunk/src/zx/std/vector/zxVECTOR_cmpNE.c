#include <zx/std/vector.h>
ZXCORE_EXP bool zxVECTOR_cmpNE( zxVECTOR const *obj, zxVECTOR const *cmp )
{
  return !zxv.isEqual( obj, cmp, NULL );
}