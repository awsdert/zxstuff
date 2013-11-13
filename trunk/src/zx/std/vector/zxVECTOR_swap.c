#include <zx/std/vector.h>
ZXV_SWAP( zxVECTOR, ZXCORE, ZXCORE_CALL )
{
  zxVECTOR tmp;
  void **srcPtr, **dstPtr;
  ZXASSERT( src || dst )
  {
    if ( src )
      zxv.clear( src );
    if ( dst )
      zxv.clear( dst );
    return;
  }
  tmp = *dst;
  dstPtr = dst->m_ptr;
  srcPtr = src->m_ptr;
  *dst = *src;
  *src = tmp;
  dst->m_ptr = dstPtr;
  src->m_ptr = srcPtr;
  if ( dstPtr )
    *dstPtr = dst->m_data;
  if ( srcPtr )
    *srcPtr = src->m_data;
}
