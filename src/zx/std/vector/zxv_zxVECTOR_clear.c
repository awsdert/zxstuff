#include <zx/std/vector.h>
ZXCORE_EXP void zxv_zxVECTOR_clear( zxVECTOR *obj )
{
  if ( !obj )
    return;
  memset( obj->m_data, 0, obj->m_size );
  obj->m_count = 0;
  obj->m_size  = 0;
}