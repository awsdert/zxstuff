/* USER: AWSDERT; DATE: 09/11/2013; TIME: 07:25 */
#include <zx/std/wide.h>
ZXV_PUSH( zxWIDE, wide, ZXCORE, ZXCORE_CALL )
{
  size_t stop;
  ZXASSERT( !src ) return false;
  if ( !zxv.push( &src->m_core, (void* const)&cpy, pos, unique ) )
    return false;
  stop = zxw.size( src );
  if ( stop == zxw.max_size( src ) )
  {
    zxv.grow( &src->m_core, stop + 1, NULL );
    zxv.erase( &src->m_core, stop, -1 );
  }
  return true;
}
