#include <zx/std/wide.h>
ZXV_PUSH_BACK( zxWIDE, wide, ZXCORE, ZXCORE_CALL )
{
  zxui stop;
  ZXASSERT( !src ) return false;
  if ( !zxv.push_back( &src->m_core, (void* const)&cpy, unique ) )
    return false;
  stop = zxw.size( src );
  if ( stop == zxw.max_size( src ) )
  {
    zxv.grow( &src->m_core, stop + 1, NULL );
    zxv.erase( &src->m_core, stop, -1 );
  }
  return true;
}
