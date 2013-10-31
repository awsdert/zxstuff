#include <zx/std/vector.h>
void zxVECTOR__init(
  zxVECTOR   *src, size_t Tsize,
  void const *cpy, size_t count )
{
  ZXASSERT( !src ) return;
  *src = zxv.def;
  src->m_Tsize = Tsize;
  if ( !cpy || !count )
    return;
  src->m_count     = count;
  src->m_fullCount = count;
  src->m_size      = count * Tsize;
  src->m_fullSize  = src->m_size;
  src->m_data      = mnew( src->m_size, cpy );
}