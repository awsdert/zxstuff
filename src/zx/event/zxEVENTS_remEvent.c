#include <zx/event.h>
ZXSYS_EXP void zxEVENTS_remEvent( zxEVENTS *src, zxEVTPTR ptr )
{
  size_t i = 0, stop = zxevt.size( src );
  ZXASSERT( !src ) return;
  for ( ; i < stop; ++i )
  {
    if ( src->m_data[ i ].event == ptr.event )
    {
      zxevt.erase( src, i, i );
      return;
    }
  }
}