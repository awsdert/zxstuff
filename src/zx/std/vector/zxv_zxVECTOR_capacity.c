#include <zx/std/vector.h>
ZXCORE_EXP size_t zxv_zxVECTOR_capacity( zxVECTOR const *obj )
{
  if ( !obj )
    return 0;
  return obj->m_fullSize;
}