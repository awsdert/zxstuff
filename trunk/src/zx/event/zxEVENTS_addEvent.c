#include <zx/event.h>
ZXSYS_EXP bool zxEVENTS_addEvent( zxEVENTS* src, zxEVTPTR ptr )
{
  zxEVTPTR evt;
  size_t i = 0, stop = zxevt.size( src );
  ZXASSERT( !src ) return false;
  for ( ; i < stop; ++i )
  {
    evt = src->m_data[ i ];
    if ( evt.event == ptr.event )
      return true;
  }
  zxevt.grow( src, stop + 1, ptr );
  return ( stop == zxevt.size( src ) );
}