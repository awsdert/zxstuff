#include <zx/std/vector.h>
void zxv_zxVECTOR__init(
  zxVECTOR   *src, size_t Tsize,
  void const *cpy, size_t count )
{
  zxuc *DST;
  zxuc const *CPY = (zxuc const*)cpy;
  size_t i = 0, B = 0;
  ZXASSERT( !src ) return;
  *src = zxv.def;
  src->m_Tsize = Tsize;
  if ( !cpy || !count )
    return;
  zxv.grow( src, count, NULL );
  DST = (zxuc*)src->m_data;
  for ( ; i < count; ++i )
    mcpy( &DST[ B ], &CPY[ B ], Tsize );
}