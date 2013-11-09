/* USER: AWSDERT; DATE: 09/11/2013; TIME: 07:38 */
#include <zx/std/char.h>
ZXV_PUSH( zxCHAR, char, ZXCORE_EXP )
{
  size_t stop;
  ZXASSERT( !src ) return false;
  if ( !zxv.push( &src->m_core, (void* const)&cpy, pos, unique ) )
    return false;
  stop = zxc.size( src );
  if ( stop == zxc.max_size( src ) )
  {
    zxv.grow( &src->m_core, stop + 1, NULL );
    zxv.erase( &src->m_core, stop, -1 );
  }
  return true;
}