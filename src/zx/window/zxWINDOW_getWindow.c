#include <zx/window.h>
ZXSYS_EXP zxWINDOW* zxWINDOW_getWindow( size_t gid )
{
  zxOBJ *obj = zxobj.at( zxobj.allObjects(), gid );
  if ( obj && obj->type == zxOBJ_SYS_WIN )
    return (zxWINDOW*)obj->obj;
  return NULL;
}