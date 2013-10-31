#include <zx/std/vector.h>
ZXCORE_EXP void zxVECTOR_reserve( zxVECTOR *obj, size_t minSize )
{
  size_t tmp = 0u, size = zxc_size_udiv( minSize, obj->m_Tsize, &tmp );
  if ( tmp )
    ++size;
  zxv.grow( obj, size, NULL );
}