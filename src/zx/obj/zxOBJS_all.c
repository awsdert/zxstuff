#include "zxobj.h"
zxvOBJ zx_l_allObjects = {0};
ZXSYS zxvOBJ* ZXCORE_CALL zxvOBJ_all( void )
{
  return &zx_l_allObjects;
}
