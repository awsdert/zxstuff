#include <zx/event.h>
ZXSYS bool zxEVENTS_addEvent( zxEVENTS* src, zxEVTPTR ptr )
{
  return zxevt.push_back( src, ptr, true );
}
