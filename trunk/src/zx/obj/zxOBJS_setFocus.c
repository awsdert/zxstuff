﻿/* USER: AWSDERT; DATE: 07/11/2013; TIME: 18:14 */
#include <zx/obj.h>
size_t zx_l_gidFocus = 0;
ZXCORE void ZXCORE_CALL zxOBJS_setFocus( zxOBJ obj )
{
  zx_l_gidFocus = obj.gid;
}
ZXCORE zxOBJ ZXCORE_CALL zxOBJS_getFocus( void )
{
  zxOBJS *all = zxobj.allObjects();
  size_t size = zxobj.size( all );
  if ( zx_l_gidFocus >= size )
    zx_l_gidFocus = 0;
  return all->m_data[ zx_l_gidFocus ];
}
