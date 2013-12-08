#include "zxobj.h"
zxOBJ zx_l_allObjectsFocus = {0};
void ZXCORE_CALL zxvOBJ_setFocus( zxOBJ obj )
{
  zx_l_allObjectsFocus  = obj;
}
bool ZXCORE_CALL zxvOBJ_hasFocus( zxOBJ obj )
{
  return ( obj.id == zx_l_allObjectsFocus.id );
}
zxOBJ ZXCORE_CALL zxvOBJ_getFocus( void )
{
  return zx_l_allObjectsFocus;
}
