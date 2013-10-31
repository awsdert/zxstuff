#include <zx/std/vector.h>
ZXCORE_EXP void zxVECTOR__kill( zxVECTOR *obj )
{
  size_t Tsize;
  if ( !obj )
    return;
  Tsize = obj->m_Tsize;
  if ( obj->m_data )
    free( obj->m_data );
  *obj = zxv.def;
  obj->m_Tsize = Tsize;
}