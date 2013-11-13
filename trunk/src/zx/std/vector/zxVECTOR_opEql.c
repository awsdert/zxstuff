#include <zx/std/vector.h>
ZXV_OPEQL( zxVECTOR, ZXCORE, ZXCORE_CALL )
{
  void** ptr = NULL;
  if ( src )
  {
    zxv._kill( src );
    if ( src )
    {
      ptr = src->m_ptr;
      *src = *cpy;
      src->m_data = (zxuc*)malloc( src->m_fullSize );
      mcpy( src->m_data, cpy->m_data, src->m_fullSize );
      if ( ptr )
        *ptr = src->m_data;
      src->m_ptr = ptr;
    }
  }
  return src;
}
