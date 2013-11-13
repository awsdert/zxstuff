#include <zx/std/wide.h>
ZXV_OPADD( zxWIDE, ZXCORE, ZXCORE_CALL )
{
  size_t stop;
  ZXASSERT( !src || !cpy ) return src;
  zxv.opAdd( &src->m_core, &cpy->m_core );
  stop = zxw.size( src );
  if ( stop == src->m_core.m_fullCount )
  {
    zxv.grow( &src->m_core, stop + 1, NULL );
    zxv.grow( &src->m_core, stop, NULL );
  }
  src->m_data = (wide*)src->m_core.m_data;
  return src;
}
