#include <zx/std/vector.h>
ZXCORE_EXP size_t zxv_zxVECTOR_max_size( zxVECTOR const *obj )
{
  if ( !obj )
    return 0;
  return obj->m_fullCount;
}