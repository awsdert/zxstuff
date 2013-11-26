#include "zxobj.h"
static size_t zx_l_allObjectsFocus = 0;
ZXCORE void ZXCORE_CALL zxvOBJ_setFocus( zxOBJ obj )
{
  zx_l_allObjectsFocus  = obj.id;
}
ZXCORE bool ZXCORE_CALL zxvOBJ_hasFocus( zxOBJ obj )
{
  return ( obj.id == zx_l_allObjectsFocus );
}
ZXCORE zxOBJ ZXCORE_CALL zxvOBJ_getFocus( void )
{
  zxvOBJ *src = zxobj.all();
  size_t size = zxobj.size( src );
  if ( zx_l_allObjectsFocus >= size )
    return zxobj.defObj;
  return src->m_data[ zx_l_allObjectsFocus ];
}
