#include "zxobj.h"
static size_t zx_l_allObjectsFocus = 0;
void ZXCORE_CALL zxvOBJ_setFocus( zxOBJ obj )
{
  zx_l_allObjectsFocus  = obj.id;
}
bool ZXCORE_CALL zxvOBJ_hasFocus( zxOBJ obj )
{
  return ( obj.id == zx_l_allObjectsFocus );
}
zxOBJ ZXCORE_CALL zxvOBJ_getFocus( void )
{
  zxvOBJ *src = zxobj.all();
  size_t size = zxobj.size( src );
  if ( zx_l_allObjectsFocus >= size )
    return zxobj.defObj;
  return src->m_data[ zx_l_allObjectsFocus ];
}
