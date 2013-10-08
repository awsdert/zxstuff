#include <zx/std//vector.h>
ZXCORE_EXP void zxv_zxVECTOR_shrink_to_fit( zxVECTOR* obj )
{
  if ( !obj )
  {
    assert( !obj );
    return;
  }
  zxv.shrink( obj, obj->m_count );
}