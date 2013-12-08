#include <zx/std/vector.h>
ZXV_RESERVE( zxVECTOR, ZXCORE, ZXCORE_CALL )
{
  size_t tmp = 0u;
  zxui size = 0;
  ZXASSERT( !src ) return;
  size = zxdivu_size( minSize, src->m_Tsize, &tmp ) & ZXUINT_MAX;
  if ( tmp )
    ++size;
  zxv.grow( src, size, NULL );
}
