#include <zx/std/wide.h>
ZXV_PUSH_BACK( zxWIDE, ZXCORE_EXP )
{
  size_t stop;
  ZXASSERT( !src || !cpy )
    return false;
  if ( !zxv.push_back( &src->m_core, &cpy->m_core ) )
  {
    src->m_data = (wide*)src->m_core.m_data;
    return false;
  }
  stop = zxw.size( src );
  if ( stop == zxw.max_size( src ) )
  {
    zxv.grow( &src->m_core, stop + 1, NULL );
    zxv.grow( &src->m_core, stop, NULL );
  }
  src->m_data = (wide*)src->m_core.m_data;
  return true;
}