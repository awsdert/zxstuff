#include <zx/std/vector.h>
ZXCORE_EXP void zxVECTOR_pop_back( zxVECTOR *obj )
{
  zxv.erase( obj, obj->m_count - 1, obj->m_count );
}