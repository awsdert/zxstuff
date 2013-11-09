#include <zx/std/vector.h>
ZXV_RESERVE( zxVECTOR, ZXCORE_EXP )
{
  size_t tmp = 0u, size;
  ZXASSERT( !src ) return;
  size = zxc_size_udiv( minSize, src->m_Tsize, &tmp );
  if ( tmp )
    ++size;
  zxv.grow( src, size, NULL );
}
