#include <zx/event.h>
ZXSYS_EXP bool zxEVENTS_addEvent( zxEVENTS* src, zxEVTPTR ptr )
{
  zxEVTPTR evt;
  size_t i = 0, stop = zxevt.size( src );
  ZXASSERT( !src ) return false;
  for ( ; i < stop; ++i )
  {
    evt = src->m_data[ i ];
    if ( evt.proc == ptr.proc )
      return true;
  }
  zxv.grow( &src->m_core, stop + 1, &ptr );
  return ( stop != zxevt.size( src ) );
}