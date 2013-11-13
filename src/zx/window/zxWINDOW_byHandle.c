#include <zx/window.h>
ZXSYS zxWINDOW* zxWINDOW_byHandle( zxHwnd wh )
{
  zxOBJS *all = zxobj.allObjects();
  zxOBJ *obj;
  zxWINDOW* win;
  size_t i = 0, stop = zxobj.size( all );
  for ( ; i < stop; ++i )
  {
    obj = &all->m_data[ i ];
    if ( obj->type != zxOBJ_SYS_WIN )
      continue;
    win = (zxWINDOW*)obj->obj;
    if ( win->m_wh == wh )
      return win;
  }
  return NULL;
}
