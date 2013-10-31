#include <zx/std/vector.h>
ZXCORE_EXP void zxVECTOR_clear( zxVECTOR *obj )
{
  if ( !obj )
    return;
  mset( obj->m_data, 0, obj->m_size );
  obj->m_count = 0;
  obj->m_size  = 0;
}