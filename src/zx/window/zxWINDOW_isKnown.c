#include <zx/window.h>
ZXSYS bool zxWINDOW_isKnown( zxWINDOW *win )
{
  zxvOBJ *all = zxobj.all();
  size_t i = 0, stop = zxobj.size( all );
  for ( ; i < stop; ++i )
  {
    if ( win == all->m_data[ i ].obj )
      return true;
  }
  return false;
}
