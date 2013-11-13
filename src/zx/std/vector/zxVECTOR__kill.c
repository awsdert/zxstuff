#include <zx/std/vector.h>
ZXV__KILL( zxVECTOR, ZXCORE, ZXCORE_CALL )
{
  size_t Tsize;
  void **ptr;
  if ( !src )
    return;
  ptr   = src->m_ptr;
  Tsize = src->m_Tsize;
  if ( src->m_data )
    free( src->m_data );
  *src = zxv.def;
  src->m_Tsize = Tsize;
  src->m_ptr   = ptr;
}
