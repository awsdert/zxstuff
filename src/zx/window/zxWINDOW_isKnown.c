#include <zx/window.h>
ZXSYS_EXP bool zxWINDOW_isKnown( zxWINDOW *win )
{
  zxOBJS *all = zxobj.allObjects();
  size_t i = 0, stop = zxobj.size( all );
  for ( ; i < stop; ++i )
  {
    if ( win == all->m_data[ i ].obj )
      return true;
  }
  return false;
}