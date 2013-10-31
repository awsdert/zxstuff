#include <zx/std/vector.h>
ZXV_RESIZE( zxVECTOR, void*, ZXCORE_EXP )
{
  ZXASSERT( !src ) return;
  if ( setCount == src->m_count ) return;
  if ( setCount < src->m_count )
  {
    zxv.erase( src, setCount, src->m_count );
    return;
  }
  zxv.grow( src, setCount, setNew );
}