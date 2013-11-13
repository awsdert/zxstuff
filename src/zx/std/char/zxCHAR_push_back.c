#include <zx/std/char.h>
ZXV_PUSH_BACK( zxCHAR, char, ZXCORE, ZXCORE_CALL )
{
  size_t stop;
  ZXASSERT( !src ) return false;
  if ( !zxv.push_back( &src->m_core, (void* const)&cpy, unique ) )
    return false;
  stop = zxc.size( src );
  if ( stop == zxc.max_size( src ) )
  {
    zxv.grow( &src->m_core, stop + 1, NULL );
    zxv.erase( &src->m_core, stop, -1 );
  }
  return true;
}
