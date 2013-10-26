#include <zx/std/vector.h>
void zxv_zxVECTOR__init(
  zxVECTOR   *src, size_t Tsize,
  void const *cpy, size_t count )
{
  ZXASSERT( !src ) return;
  *src = zxv.def;
  src->m_Tsize = Tsize;
  if ( !cpy || !count )
    return;
  zxv.grow( src, count, NULL );
  mcpy( src->m_data, cpy, src->m_size );
}