#include <zx/std/char.h>
ZXV_PUSH_BACK( zxCHAR, ZXCORE_EXP )
{
  size_t stop;
  ZXASSERT( !src || !cpy )
    return false;
  if ( !zxv.push_back( &src->m_core, &cpy->m_core ) )
  {
    src->m_data = (char*)src->m_core.m_data;
    return false;
  }
  stop = zxc.size( src );
  if ( stop == zxc.max_size( src ) )
  {
    zxv.grow( &src->m_core, stop + 1, NULL );
    zxv.grow( &src->m_core, stop, NULL );
  }
  src->m_data = (char*)src->m_core.m_data;
  return true;
}