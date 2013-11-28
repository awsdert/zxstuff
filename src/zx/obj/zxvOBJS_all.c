#include "zxobj.h"
static zxvOBJ zx_l_allObjects = {0};
zxvOBJ* ZXCORE_CALL zxvOBJ_all( void )
{
  return &zx_l_allObjects;
}
