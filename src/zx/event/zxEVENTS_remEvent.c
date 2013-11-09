#include <zx/event.h>
ZXSYS_EXP void zxEVENTS_remEvent( zxEVENTS *src, zxEVTPTR ptr )
{
  zxevt.pop( src, ptr, 0, -1 );
}